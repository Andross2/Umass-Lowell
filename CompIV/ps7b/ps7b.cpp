// Copyright Chuong Vu
// Filename: ps7b.cpp
#include <iostream>
#include <fstream>  // for read input file
#include <sstream>  // Required for stringstreams
#include <string>
#include "boost/regex.hpp"  // for regex_match library
#include "kronos_parse.hpp"
#include "boost/date_time/gregorian/gregorian.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::ostringstream;

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

string IntToString(int a) {
    ostringstream temp;
    temp << a;
    return temp.str();
}

int main(int argc, char* argv[]) {
    string line;
    int line_order = 1;
    bool boot = false;
    bool check = false;
    int time1, time2;
    // Posix Time
    ptime t1, t2;

    string time;
    string outputName;
    ofstream outputFile;

    ostringstream ss;
    ss.str("");

         // Check # of Command Line Args
    if (argc != 2) {
        throw std::runtime_error("Usage: enter one log file");
    }

    // Open Device Log, end if it can't be opened.
    ifstream inputFile(argv[1], ifstream::in);
    if (!inputFile.is_open()) {
        throw std::runtime_error("Cannot open file");
    }
    string inputName = string(argv[1]);
    outputName = string(argv[1]) + ".rpt";
    outputFile.open(outputName.c_str());

    // Construct regular expression
    // YYYY -MM -DD format
    string sdate("([0-9]{4})-([0-9]{1,2})-([0-9]{1,2}) ");
    // Time format
    string stime("([0-9]{2}):([0-9]{2}):([0-9]{2})");
    // boot start
    string sboot("(.*log.c.166.*)");
    // boot start success
    string sdone("(.*oejs.AbstractConnector:Started SelectChannelConnector.*)");

    // Regular expression for regex use to compare
    // Boot time
    regex e_begin_boot(sdate + stime + sboot);
    regex e_end_boot(sdate + stime + sdone);
    //  Start and succe started
    string sstart("(.*Starting Service.)");
    string ssuccess("(.*Service started successfully.)");
    string sruntime("\\((.*)\\)");

    //  1.Logging
    string slogging("(..Logging.*)");
    regex e_slog_start(sstart + slogging);
    regex e_slog_done(ssuccess + slogging + sruntime);

    //  2.DatabaseInitialize
    string sdatainit("(..DatabaseInitialize.*)");
    regex e_datainit_start(sstart + sdatainit);
    regex e_datainit_done(ssuccess + sdatainit + sruntime);

    //  3.MessagingService
    string smesser("(..MessagingService.*)");
    regex e_messer_start(sstart + smesser);
    regex e_messer_done(ssuccess + smesser + sruntime);

    //  4.HealthMonitorService
    string shealth("(..HealthMonitorService.*)");
    regex e_health_start(sstart + shealth);
    regex e_health_done(ssuccess + shealth + sruntime);

    //  5.Persistence
    string sperser("(..Persistence.*)");
    regex e_sperser_start(sstart + sperser);
    regex e_sperser_done(ssuccess + sperser + sruntime);

    //  6.ConfigurationService
    string sconser("(..ConfigurationService.*)");
    regex e_sconser_start(sstart + sconser);
    regex e_sconser_done(ssuccess + sconser + sruntime);

    //  7.LandingPadService
    string slser("(..LandingPadService.*)");
    regex e_slser_start(sstart + slser);
    regex e_slser_done(ssuccess + slser + sruntime);

    //  8.PortConfigurationService
    string sportcon("(..PortConfigurationService.*)");
    regex e_sportcon_start(sstart + sportcon);
    regex e_sportcon_done(ssuccess + sportcon + sruntime);

    //  9.CacheService
    string scser("(..CacheService.*)");
    regex e_scser_start(sstart + scser);
    regex e_scser_done(ssuccess + scser + sruntime);

    //  10.ThemingService
    string sthemser("(..ThemingService.*)");
    regex e_sthemser_start(sstart + sthemser);
    regex e_sthemser_done(ssuccess + sthemser + sruntime);

    //  11.StagingService
    string sstaser("(..StagingService.*)");
    regex e_sstaser_start(sstart + sstaser);
    regex e_sstaser_done(ssuccess + sstaser + sruntime);

    //  12.DeviceIOService
    string sdevser("(..DeviceIOService.*)");
    regex e_sdevser_start(sstart + sdevser);
    regex e_sdevser_done(ssuccess + sdevser + sruntime);

    //  13.BellService
    string sbellser("(..BellService.*)");
    regex e_sbellser_start(sstart + sbellser);
    regex e_sbellser_done(ssuccess + sbellser + sruntime);

    //  14.GateService
    string sgateser("(..GateService.*)");
    regex e_sgateser_start(sstart + sgateser);
    regex e_sgateser_done(ssuccess + sgateser + sruntime);

    //  15.ReaderDataService
    string sreadser("(..ReaderDataService.*)");
    regex e_sreadser_start(sstart + sreadser);
    regex e_sreadser_done(ssuccess + sreadser + sruntime);

    //  16.BiometricService
    string sbioser("(..BiometricService.*)");
    regex e_sbioser_start(sstart + sbioser);
    regex e_sbioser_done(ssuccess + sbioser + sruntime);

    //  17.StateManager
    string stateser("(..StateManager.*)");
    regex e_stateser_start(sstart + stateser);
    regex e_stateser_done(ssuccess + stateser + sruntime);

    //  18.OfflineSmartviewService
    string soffser("(..OfflineSmartviewService.*)");
    regex e_soffser_start(sstart + soffser);
    regex e_soffser_done(ssuccess + soffser + sruntime);

    //  19.AVFeedbackService
    string savfser("(..AVFeedbackService.*)");
    regex e_savfser_start(sstart + savfser);
    regex e_savfser_done(ssuccess + savfser + sruntime);

    //  20.DatabaseThreads
    string sdataser("(..DatabaseThreads.*)");
    regex e_sdataser_start(sstart + sdataser);
    regex e_sdataser_done(ssuccess + sdataser + sruntime);

    //  21.SoftLoadService
    string ssoftser("(..SoftLoadService.*)");
    regex e_ssoftser_start(sstart + ssoftser);
    regex e_ssoftser_done(ssuccess + ssoftser + sruntime);

    //  22.WATCHDOG
    string swatser("(..WATCHDOG.*)");
    regex e_swatser_start(sstart + swatser);
    regex e_swatser_done(ssuccess + swatser + sruntime);

    //  23.ProtocolService
    string sprotoser("(..ProtocolService.*)");
    regex e_sprotoser_start(sstart + sprotoser);
    regex e_sprotoser_done(ssuccess + sprotoser + sruntime);

    //  24.DiagnosticsService
    string sdiagser("(..DiagnosticsService.*)");
    regex e_sdiagser_start(sstart + sdiagser);
    regex e_sdiagser_done(ssuccess + sdiagser + sruntime);

    //  Softload start
    string softdate("(Jan|Feb|Mar|Apr|May|Jun|Jul|Aug|Sep|Oct|Nov|Dec|Dec)");
    string softdate1("([\\s]+)([0-9]{1,2}).");
    string softload(".*(SOFTLOADSERVICE.*)");
    string softstart("(.*Install started.*)");
    regex e_softload_start(softdate + softdate1 + stime + softload + softstart);

    //  Softload original
    string softori1("(.*removing intouch-application-base-)");
    string softori2("(.*)(.armv6jel_vfp.rpm.*)");
    regex e_soffser_orgi(softori1 + softori2);

    //  Softload newverion
    string softnew1("(.*Processing.[0-9]{1,2}.of.[0-9]{1,2}.)");
    string softnew2("(intouch-application-base-)(.*)(.armv6jel_vfp.rpm.*)");
    regex e_softload_new(softnew1 + softnew2);

    //  Softload done
    string softdone1("(Jan|Feb|Mar|Apr|May|Jun|Jul|Aug|Sep|Oct|Nov|Dec)");
    string softdone2("([\\s]+)([0-9]{1,2}).([0-9]{2}):([0-9]{2}):([0-9]{2})");
    string softdone3("(.*ExitValue from install command.*)");
    regex e_softload_done(softdone1 + softdone2 + softdone3);

    //  create default construct class Kronos
    Kronos logfile(inputName);

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
                outputFile << logfile.getStr();
                logfile.reset();
                boot = false;
                check = false;
            }
            outputFile << "=== Device boot ===" << endl
                        << line_order << "(" << inputName << "): "
                        << m[1] << "-" << m[2] << "-" << m[3] << " "  //  date
                        << m[4] << ":" << m[5] << ":" << m[6] << " "  //  time
                        << "Boot Start" << endl;
            boot = true;
            check = true;
        } else if (regex_match(line, m, e_end_boot)) {
            if (boot) {
                date d(from_simple_string(m[0]));
                ptime temp(d, time_duration(to_int(m[4]),
                                            to_int(m[5]), to_int(m[6])));
                t2 = temp;
                time_duration td = t2 - t1;
                outputFile << line_order << "(" << inputName << "): "
                        << m[1] << "-" << m[2] << "-" << m[3] << " "  //  date
                        << m[4] << ":" << m[5] << ":" << m[6] << " "  //  time
                        << "Boot Completed" << endl
                        << "\t" << "Boot Time: "
                        << td.total_milliseconds() << "ms\n" << endl;
                outputFile << logfile.getStr();
                logfile.reset();
                boot = false;
                check = false;
            } else {
                outputFile << "**** Incomplete boot12345 **** \n" << endl;
            }
            check = false;
        }

        if (check) {
            //  1.Logging
            if (regex_match(line, m, e_slog_start)) {
                logfile.update(1, 1, IntToString(line_order), "");
            } else if (regex_match(line, m, e_slog_done)) {
                time = m[3];
                logfile.update(1, 2, IntToString(line_order), time);
            //  2.DatabaseInitialize
            } else if (regex_match(line, m, e_datainit_start)) {
                logfile.update(2, 1, IntToString(line_order), "");
            } else if (regex_match(line, m, e_datainit_done)) {
                time = m[3];
                logfile.update(2, 2, IntToString(line_order), time);
            //  3.MessagingService
            } else if (regex_match(line, m, e_messer_start)) {
                logfile.update(3, 1, IntToString(line_order), "");
            } else if (regex_match(line, m, e_messer_done)) {
                time = m[3];
                logfile.update(3, 2, IntToString(line_order), time);
            //  4.HealthMonitorService
            } else if (regex_match(line, m, e_health_start)) {
                logfile.update(4, 1, IntToString(line_order), "");
            } else if (regex_match(line, m, e_health_done)) {
                time = m[3];
                logfile.update(4, 2, IntToString(line_order), time);
            //  5.Persistence
            } else if (regex_match(line, m, e_sperser_start)) {
                logfile.update(5, 1, IntToString(line_order), "");
            } else if (regex_match(line, m, e_sperser_done)) {
                time = m[3];
                logfile.update(5, 2, IntToString(line_order), time);
            //  6.ConfigurationService
            } else if (regex_match(line, m, e_sconser_start)) {
                logfile.update(6, 1, IntToString(line_order), "");
            } else if (regex_match(line, m, e_sconser_done)) {
                time = m[3];
                logfile.update(6, 2, IntToString(line_order), time);
            //  7.LandingPadService
            } else if (regex_match(line, m, e_slser_start)) {
                logfile.update(7, 1, IntToString(line_order), "");
            } else if (regex_match(line, m, e_slser_done)) {
                time = m[3];
                logfile.update(7, 2, IntToString(line_order), time);
            //  8.PortConfigurationService
            } else if (regex_match(line, m, e_sportcon_start)) {
                logfile.update(8, 1, IntToString(line_order), "");
            } else if (regex_match(line, m, e_sportcon_done)) {
                time = m[3];
                logfile.update(8, 2, IntToString(line_order), time);
            //  9.CacheService
            } else if (regex_match(line, m, e_scser_start)) {
                logfile.update(9, 1, IntToString(line_order), "");
            } else if (regex_match(line, m, e_scser_done)) {
                time = m[3];
                logfile.update(9, 2, IntToString(line_order), time);
            //  10.ThemingService
            } else if (regex_match(line, m, e_sthemser_start)) {
                logfile.update(10, 1, IntToString(line_order), "");
            } else if (regex_match(line, m, e_sthemser_done)) {
                time = m[3];
                logfile.update(10, 2, IntToString(line_order), time);
            //  11.StagingService
            } else if (regex_match(line, m, e_sstaser_start)) {
                logfile.update(11, 1, IntToString(line_order), "");
            } else if (regex_match(line, m, e_sstaser_done)) {
                time = m[3];
                logfile.update(11, 2, IntToString(line_order), time);
            //  12.DeviceIOService
            } else if (regex_match(line, m, e_sdevser_start)) {
                logfile.update(12, 1, IntToString(line_order), "");
            } else if (regex_match(line, m, e_sdevser_done)) {
                time = m[3];
                logfile.update(12, 2, IntToString(line_order), time);
            //  13.BellService
            } else if (regex_match(line, m, e_sbellser_start)) {
                logfile.update(13, 1, IntToString(line_order), "");
            } else if (regex_match(line, m, e_sbellser_done)) {
                time = m[3];
                logfile.update(13, 2, IntToString(line_order), time);
            //  14.GateService
            } else if (regex_match(line, m, e_sgateser_start)) {
                logfile.update(14, 1, IntToString(line_order), "");
            } else if (regex_match(line, m, e_sgateser_done)) {
                time = m[3];
                logfile.update(14, 2, IntToString(line_order), time);
            //  15.ReaderDataService
            } else if (regex_match(line, m, e_sreadser_start)) {
                logfile.update(15, 1, IntToString(line_order), "");
            } else if (regex_match(line, m, e_sreadser_done)) {
                time = m[3];
                logfile.update(15, 2, IntToString(line_order), time);
            //  16.BiometricService
            } else if (regex_match(line, m, e_sbioser_start)) {
                logfile.update(16, 1, IntToString(line_order), "");
            } else if (regex_match(line, m, e_sbioser_done)) {
                time = m[3];
                logfile.update(16, 2, IntToString(line_order), time);
            //  17.StateManager
            } else if (regex_match(line, m, e_stateser_start)) {
                logfile.update(17, 1, IntToString(line_order), "");
            } else if (regex_match(line, m, e_stateser_done)) {
                time = m[3];
                logfile.update(17, 2, IntToString(line_order), time);
            //  18.OfflineSmartviewService
            } else if (regex_match(line, m, e_soffser_start)) {
                logfile.update(18, 1, IntToString(line_order), "");
            } else if (regex_match(line, m, e_soffser_done)) {
                time = m[3];
                logfile.update(18, 2, IntToString(line_order), time);
            //  19.AVFeedbackService
            } else if (regex_match(line, m, e_savfser_start)) {
                logfile.update(19, 1, IntToString(line_order), "");
            } else if (regex_match(line, m, e_savfser_done)) {
                time = m[3];
                logfile.update(19, 2, IntToString(line_order), time);
            //  20.DatabaseThreads
            } else if (regex_match(line, m, e_sdataser_start)) {
                logfile.update(20, 1, IntToString(line_order), "");
            } else if (regex_match(line, m, e_sdataser_done)) {
                time = m[3];
                logfile.update(20, 2, IntToString(line_order), time);
            //  21.SoftLoadService
            } else if (regex_match(line, m, e_ssoftser_start)) {
                logfile.update(21, 1, IntToString(line_order), "");
            } else if (regex_match(line, m, e_ssoftser_done)) {
                time = m[3];
                logfile.update(21, 2, IntToString(line_order), time);
            //  22.WATCHDOG
            } else if (regex_match(line, m, e_swatser_start)) {
                logfile.update(22, 1, IntToString(line_order), "");
            } else if (regex_match(line, m, e_swatser_done)) {
                time = m[3];
                logfile.update(22, 2, IntToString(line_order), time);
            //  23.ProtocolService
            } else if (regex_match(line, m, e_sprotoser_start)) {
                logfile.update(23, 1, IntToString(line_order), "");
            } else if (regex_match(line, m, e_sprotoser_done)) {
                time = m[3];
                logfile.update(23, 2, IntToString(line_order), time);
            //  24.DiagnosticsService
            } else if (regex_match(line, m, e_sdiagser_start)) {
                logfile.update(24, 1, IntToString(line_order), "");
            } else if (regex_match(line, m, e_sdiagser_done)) {
                time = m[3];
                logfile.update(24, 2, IntToString(line_order), time);
            }
        }

        //  SoftLoad start
        if (regex_match(line, m, e_softload_start)) {
            time1 = (to_int(m[4]) * 3600) + (to_int(m[5]) * 60) + to_int(m[6]);
            time = m[1] + " " + m[3] + " " + m[4] + ":" + m[5] + ":" + m[6];
            // cout << time << endl;
            logfile.update(25, 1, IntToString(line_order), time);
        } else if (regex_match(line, m, e_softload_new)) {  //  SoftLoad new
            time = m[3];
             // cout << time << endl;
            logfile.update(25, 2, IntToString(line_order), time);
        } else if (regex_match(line, m, e_soffser_orgi)) {  //  SoftLoad orig
            time = m[2];
             // cout << time << endl;
            logfile.update(25, 3, IntToString(line_order), time);
        } else if (regex_match(line, m, e_softload_done)) {  //  SoftLoad end
            time2 = (to_int(m[4]) * 3600) + (to_int(m[5]) * 60) + to_int(m[6]);
            time = m[1] + " " + m[3] + " " + m[4] + ":" + m[5] + ":" + m[6];
             // cout << time << endl;
            logfile.update(25, 4, IntToString(line_order), time);
            logfile.update(25, 5, IntToString(time2 - time1), time);
            outputFile << logfile.getsl();
        }
        line_order++;
    }
    return 0;
}
