#!/bin/bash
dir=$(readlink -f $(dirname $0)/..)

ulimit -s unlimited

cd $dir

FATHOM_PRESENT=0
if [ -e Fathom/src/tbprobe.h ]; then
   FATHOM_PRESENT=1
   echo "found Fathom lib, trying to build"
   $dir/Tools/buildFathom.sh "$@"
fi

mkdir -p $dir/Dist/Minic2

d="-DDEBUG_TOOL"
v="dev"
t="-march=native"

if [ -n "$1" ] ; then
   v=$1
   shift
fi

if [ -n "$1" ] ; then
   t=$1
   shift
fi

g++ -v
echo "version $v"
echo "definition $d"
echo "target $t"

exe=minic_${v}_linux_x64
if [ "$t" != "-march=native" ]; then
   tname=$(echo $t | sed 's/-m//g' | sed 's/arch=//g' | sed 's/ /_/g')
   exe=${exe}_${tname}
fi

echo "Building $exe"

WARN="-Wall -Wcast-qual -Wno-char-subscripts -Wno-reorder -Wmaybe-uninitialized -pedantic -Wextra -Wshadow -Wfatal-errors"

OPT="-s $WARN $d -DNDEBUG -O3 $t --std=c++14" ; DEPTH=20
#OPT="$WARN $d -DNDEBUG -g $t --std=c++14" ; DEPTH=10
#OPT="$WARN $d -g $t --std=c++14" ; DEPTH=10

# -flto is making g++ 9.3.0 under cygwin segfault
uname -a | grep CYGWIN
if [ $? == 1 ]; then
   OPT="$OPT -flto"
fi

echo $OPT

if [ $FATHOM_PRESENT = "1" ]; then
   lib=fathom_${v}_linux_x64
   if [ "$t" != "-march=native" ]; then
      tname=$(echo $t | sed 's/-m//g' | sed 's/arch=//g' | sed 's/ /_/g')
      lib=${lib}_${tname}
   fi
   lib=${lib}.o
   OPT="$OPT $dir/Fathom/src/$lib -I$dir/Fathom/src"
fi

rm -f *.gcda

g++ -fprofile-generate $OPT Source/*.cpp -ISource -o $dir/Dist/Minic2/$exe -lpthread 
echo "end of first compilation"
if [ $? = "0" ]; then
   echo "running Minic for profiling : $dir/Dist/Minic2/$exe"
   $dir/Dist/Minic2/$exe bench $DEPTH -quiet 0 
   #$dir/Dist/Minic2/$exe -analyze "shirov" 20 
   echo "starting optimized compilation"
   g++ -fprofile-use $OPT Source/*.cpp -ISource -o $dir/Dist/Minic2/$exe -lpthread
   echo "done "
else
   echo "some error"
fi

rm -f *.gcda
