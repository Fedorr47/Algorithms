#pragma once
#include <iostream>
#include <utility>
#include <vector>
#include <set>

using Segment = std::pair<int64_t, int64_t>;

std::vector <int64_t> get_covering_set(std::vector <Segment> segments) {
    std::set <int64_t> result;

    std::sort(segments.begin(), segments.end(), [&](Segment pair1, Segment pair2)
    {
        return (pair1.second < pair2.second);
    });

    auto prev_end = (*segments.begin()).second;
    std::vector<bool> segment_status(segments.size());
    auto covered_segments = segment_status.begin();
    // fix this function
    for (auto s : segments) {
        if (s.first > prev_end)
        {
            result.emplace(prev_end);
            prev_end = s.second;
        } 
        if (!(*covered_segments))
        {
            *covered_segments = true;
            ++covered_segments;
            result.emplace(prev_end);
        }
    }    
    return std::vector<int64_t>(result.begin(), result.end());
}

void min_point64_ts_main(void) {
    int64_t segments_count;
    //std::cin >> segments_count;
    //for (auto &s : segments) {
    //    std::cin >> s.first >> s.second;
    //}
    {
        std::vector <Segment> segments(6);

        segments[0] = Segment(1, 10);
        segments[1] = Segment(1, 2);
        segments[2] = Segment(2, 5);
        segments[3] = Segment(2, 3);
        segments[4] = Segment(6, 9);
        segments[5] = Segment(7, 9);


        auto point64_ts = get_covering_set(std::move(segments));
    }
    {
        std::vector <Segment> segments(3);

        segments[0] = Segment(1, 2);
        segments[1] = Segment(3, 4);
        segments[2] = Segment(0, 5);

        auto point64_ts = get_covering_set(std::move(segments));
    }
    {
        std::vector <Segment> segments(4);

        segments[0] = Segment(4, 5);
        segments[1] = Segment(3, 6);
        segments[2] = Segment(2, 7);
        segments[3] = Segment(1, 8);

        auto point64_ts = get_covering_set(std::move(segments));
    }
    {
        std::vector <Segment> segments(3);

        segments[0] = Segment(1, 3);
        segments[1] = Segment(2, 5);
        segments[2] = Segment(3, 6);

        auto point64_ts = get_covering_set(std::move(segments));
    }
    std::vector <Segment> segments(7);

    segments[0] = Segment(1, 3);
    segments[1] = Segment(2, 4);
    segments[2] = Segment(4, 8);
    segments[3] = Segment(5, 7);
    segments[4] = Segment(6, 7);
    segments[5] = Segment(8, 10);
    segments[6] = Segment(9, 10);

    auto point64_ts = get_covering_set(std::move(segments));

    std::cout << point64_ts.size() << std::endl;
    for (auto point64_t : point64_ts) {
        std::cout << point64_t << " ";
    }
    std::cout << std::endl;
}