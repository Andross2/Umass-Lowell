// Copyright Chuong Vu
// Filename: ps7a.cpp

#include <boost/regex.hpp>  // for regex_match library
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <iostream>
#include <fstream>  // for read input file
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;

using boost::regex;
using boost::gregorian::date;
using boost::gregorian::from_simple_string;  // convert string to date library
using boost::gregorian::date_period;
using boost::gregorian::date_duration;
using boost::posix_time::ptime;
using boost::posix_time::time_duration;

// The function based on Prof. Victor Grinberg lecture capture
// instantiate the template for any type has the str() member
// function that returns an std::string
template <typename T>
int to_int(const T& sm) {
    return atoi(sm.str().c_str());
}

int main(int argc, char* argv[]) {
    string line;
    int line_order = 1;
    bool boot = false;
    // Posix Time
    ptime t1, t2;
    std::vector<string> checklist;
    string outputName;
    ofstream outputFile;
    // Construct regular expression
    // YYYY -MM -DD format
    string sdate("([0-9]{4})-([0-9]{1,2})-([0-9]{1,2}) ");
    // Time format
    string stime("([0-9]{2}):([0-9]{2}):([0-9]{2})");
    // boot start
    string sboot("(.*log.c.166.*)");
    // boot start success
    string sdone("(.*oejs.AbstractConnector:Started SelectChannelConnector.*)");

    // Check # of Command Line Args
    if (argc != 2) {
        throw std::runtime_error("Usage: enter one log file");
    }

    // Open Device Log, end if it can't be opened.
    ifstream inputFile(argv[1], ifstream::in);
    if (!inputFile.is_open()) {
        throw std::runtime_error("Cannot open file");
    }

    outputName = string(argv[1]) + ".rpt";
    outputFile.open(outputName.c_str());

    // Regular expression for regex use to compare
    regex e_begin_boot(sdate + stime + sboot);
    regex e_end_boot(sdate + stime + sdone);

    // hold matches values
    boost::smatch m;

    while (getline(inputFile, line)) {
        if (regex_match(line, m, e_begin_boot)) {
            date d(from_simple_string(m[0]));
            ptime temp(d, time_duration(to_int(m[4]),
                                        to_int(m[5]), to_int(m[6])));
            t1 = temp;
            if (boot) {
                outputFile << "**** Incomplete boot ****\n" << std::endl;
                boot = false;
            }
            outputFile << "=== Device boot ===" << endl
                        << line_order << "(" << argv[1] << "): "
                        << m[1] << "-" << m[2] << "-" << m[3] << " "
                        << m[4] << ":" << m[5] << ":" << m[6] << " "
                        << "Boot Start" << endl;
            boot = true;
        } else if (regex_match(line, m, e_end_boot)) {
            if (boot) {
                date d(from_simple_string(m[0]));
                ptime temp(d, time_duration(to_int(m[4]),
                                            to_int(m[5]), to_int(m[6])));
                t2 = temp;
                time_duration td = t2 - t1;
                outputFile << line_order << "(" << argv[1] << "): "
                            << m[1] << "-" << m[2] << "-" << m[3] << " "
                            << m[4] << ":" << m[5] << ":" << m[6] << " "
                            << "Boot Completed\n"
                            << "    " << "Boot Time: "
                            << td.total_milliseconds() << "ms \n" << endl;
                boot = false;
            } else {
                outputFile << "**** Incomplete boot **** \n" << endl;
            }
        }
        line_order++;
    }
    return 0;
}
