#pragma once

#include "definition.hpp"

#include "position.hpp"
#include "stats.hpp"

struct Searcher; // forward decl

struct ThreadData{
    DepthType depth = 0, seldepth = 0;
    ScoreType sc = 0;
    Position p;
    Move best = INVALIDMOVE;
    PVList pv;
};

/* This is the singleton pool of threads
 * The search function here is the main entry point for an analysis
 * This is based on the former Stockfish design
 */
class ThreadPool : public std::vector<std::unique_ptr<Searcher>> {
public:
    static ThreadPool & instance();
    ~ThreadPool();
    void setup();
    Searcher & main();
    Move search(const ThreadData & d);
    void startOthers();
    void wait(bool otherOnly = false);
    bool stop;
    // gathering counter information from all threads
    Counter counter(Stats::StatId id) const;
    void DisplayStats()const{for(size_t k = 0 ; k < Stats::sid_maxid ; ++k) Logging::LogIt(Logging::logInfo) << Stats::Names[k] << " " << counter((Stats::StatId)k);}
private:
    ThreadPool();
};

