#include <iostream>
#include <vector>
#include <algorithm>

struct Segment {
    int left;
    int right;
};

bool compareSegments(const Segment& seg1, const Segment& seg2) {
    return seg1.left < seg2.left;
}

void printSegments(const std::vector<Segment>& segments) {
    for (const auto& seg : segments) {
        std::cout << seg.left << " " << seg.right << std::endl;
    }
}

void coverSegment(int M, const std::vector<Segment>& segments) {
    std::vector<Segment> coveredSegments;
    int maxRight = 0;
    int i = 0;

    while (maxRight < M && i < segments.size()) {
        // Find the segment with the maximum right endpoint
        int maxRightIndex = -1;
        for (int j = i; j < segments.size(); j++) {
            if (segments[j].left > maxRight) {
                break;
            }
            if (segments[j].right > segments[maxRightIndex].right) {
                maxRightIndex = j;
            }
        }

        if (maxRightIndex == -1) {
            break;
        }

        coveredSegments.push_back(segments[maxRightIndex]);
        maxRight = segments[maxRightIndex].right;
        i = maxRightIndex + 1;
    }

    if (maxRight >= M) {
        std::cout << coveredSegments.size() << std::endl;
        printSegments(coveredSegments);
    } else {
        std::cout << "0" << std::endl;
    }
}

int main() {
    int T;
    std::cin >> T; // Number of test cases

    while (T--) {
        int M;
        std::cin >> M; // Segment [0, M]

        std::vector<Segment> segments;
        int left, right;
        while (std::cin >> left >> right && !(left == 0 && right == 0)) {
            segments.push_back({left, right});
        }

        std::sort(segments.begin(), segments.end(), compareSegments);

        coverSegment(M, segments);

        // Print a blank line between consecutive test cases
        if (T > 0) {
            std::cout << std::endl;
        }
    }

    return 0;
}
