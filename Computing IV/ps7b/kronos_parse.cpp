// Copyright Chuong Vu
// kronos_parse.cpp
#include <iostream>
#include <string>
#include "kronos_parse.hpp"

Kronos::Kronos(std::string input) : _Name(input) {
    _logging = _datainit = _messer = _health = _sperser = _sconser = _slser
    = _sportcon = _scser = _sthemser = _sstaser = _sdevser = _sbellser
    = _sgateser = _sreadser = _sbioser = _stateser = _soffser = _savfser
    = _sdataser = _ssoftser = _swatser = _sprotoser = _sdiagser = 0;
    first = true;
    _softload = false;
     ss.str("");
    //  1
    _logstart = "\tLogging\n\t\tStart: Not started(" + _Name + ")\n";
    _logcom = "\t\tCompleted: Not completed(" + _Name + ")\n"
                + "\t\tElapsed Time: \n";
    //  2
    _datainitstart = "\tDatabaseInitialize\n\t\tStart: Not started("
                    + _Name + ")\n";
    _datainitcom = "\t\tCompleted: Not completed(" + _Name + ")\n"
                    + "\t\tElapsed Time: \n";
    //  3
    _messerstart = "\tMessagingService\n\t\tStart: Not started(" + _Name
                    + ")\n";
    _messercom = "\t\tCompleted: Not completed(" + _Name + ")\n"
                    + "\t\tElapsed Time: \n";
    //  4
    _heathst = "\tHealthMonitorService\n\t\tStart: Not started(" + _Name
                + ")\n";
    _heathco = "\t\tCompleted: Not completed(" + _Name + ")\n"
            + "\t\tElapsed Time: \n";
    //  5
    _perserst = "\tPersistence\n\t\tStart: Not started(" + _Name + ")\n";
    _perserco = "\t\tCompleted: Not completed(" + _Name + ")\n"
                + "\t\tElapsed Time: \n";
    //  6
    _sconserst = "\tConfigurationService\n\t\tStart: Not started(" + _Name
                + ")\n";
    _sconserco = "\t\tCompleted: Not completed(" + _Name + ")\n"
                + "\t\tElapsed Time: \n";
    //  7
    _slserst = "\tLandingPadService\n\t\tStart: Not started(" + _Name
                + ")\n";
    _slserco = "\t\tCompleted: Not completed(" + _Name + ")\n"
                + "\t\tElapsed Time: \n";
    //  8
    _sportconst = "\tPortConfigurationService\n\t\tStart: Not started("
                + _Name + ")\n";
    _sportconco = "\t\tCompleted: Not completed(" + _Name + ")\n"
                + "\t\tElapsed Time: \n";
    //  9
    _scserst = "\tCacheService\n\t\tStart: Not started(" + _Name + ")\n";
    _scserco = "\t\tCompleted: Not completed(" + _Name + ")\n"
            + "\t\tElapsed Time: \n";
    //  10
    _sthemserst = "\tThemingService\n\t\tStart: Not started(" + _Name + ")\n";
    _sthemserco = "\t\tCompleted: Not completed(" + _Name + ")\n"
            + "\t\tElapsed Time: \n";
    //  11
    _sstaserst = "\tStagingService\n\t\tStart: Not started(" + _Name + ")\n";
    _sstaserco = "\t\tCompleted: Not completed(" + _Name + ")\n"
            + "\t\tElapsed Time: \n";
    //  12
    _sdevserst = "\tDeviceIOService\n\t\tStart: Not started(" + _Name + ")\n";
    _sdevserco = "\t\tCompleted: Not completed(" + _Name + ")\n"
            + "\t\tElapsed Time: \n";
    //  13
    _sbellserst = "\tBellService\n\t\tStart: Not started(" + _Name + ")\n";
    _sbellserco = "\t\tCompleted: Not completed(" + _Name + ")\n"
            + "\t\tElapsed Time: \n";
    //  14
    _sgateserst = "\tGateService\n\t\tStart: Not started(" + _Name + ")\n";
    _sgateserco = "\t\tCompleted: Not completed(" + _Name + ")\n"
            + "\t\tElapsed Time: \n";
    //  15
    _sreadserst = "\tReaderDataService\n\t\tStart: Not started(" + _Name
            + ")\n";
    _sreadserco = "\t\tCompleted: Not completed(" + _Name + ")\n"
            + "\t\tElapsed Time: \n";
    //  16
    _sbioserst = "\tBiometricService\n\t\tStart: Not started(" + _Name + ")\n";
    _sbioserco = "\t\tCompleted: Not completed(" + _Name + ")\n"
            + "\t\tElapsed Time: \n";
    //  17
    _stateserst = "\tStateManager\n\t\tStart: Not started(" + _Name + ")\n";
    _stateserco = "\t\tCompleted: Not completed(" + _Name + ")\n"
            + "\t\tElapsed Time: \n";
    //  18
    _soffserst = "\tOfflineSmartviewService\n\t\tStart: Not started(" + _Name
            + ")\n";
    _soffserco = "\t\tCompleted: Not completed(" + _Name + ")\n"
            + "\t\tElapsed Time: \n";
    //  19
    _savfserst = "\tAVFeedbackService\n\t\tStart: Not started(" + _Name
                + ")\n";
    _savfserco = "\t\tCompleted: Not completed(" + _Name + ")\n"
            + "\t\tElapsed Time: \n";
    //  20
    _sdataserst = "\tDatabaseThreads\n\t\tStart: Not started(" + _Name + ")\n";
    _sdataserco = "\t\tCompleted: Not completed(" + _Name + ")\n"
            + "\t\tElapsed Time: \n";
    //  21
    _ssoftserst = "\tSoftLoadService\n\t\tStart: Not started(" + _Name + ")\n";
    _ssoftserco = "\t\tCompleted: Not completed(" + _Name + ")\n"
            + "\t\tElapsed Time: \n";
    //  22
    _swatserst = "\tWATCHDOG\n\t\tStart: Not started(" + _Name + ")\n";
    _swatserco = "\t\tCompleted: Not completed(" + _Name + ")\n"
            + "\t\tElapsed Time: \n";
    //  23
    _sprotoserst = "\tProtocolService\n\t\tStart: Not started(" + _Name + ")\n";
    _sprotoserco = "\t\tCompleted: Not completed(" + _Name + ")\n"
            + "\t\tElapsed Time: \n";
    //  24
    _sdiagserst = "\tDiagnosticsService\n\t\tStart: Not started(" + _Name
            + ")\n";
    _sdiagserco = "\t\tCompleted: Not completed(" + _Name + ")\n"
            + "\t\tElapsed Time: \n";

    //  Softload
    _softloadstart = "";
    _softloador = "";
    _softloadnew = "";
    _softloadtime = "";
    _softloadelap = "";
}


void Kronos::reset(void) {
    _logging = _datainit = _messer = _health = _sperser = _sconser = _slser
    = _sportcon = _scser = _sthemser = _sstaser = _sdevser = _sbellser
    = _sgateser = _sreadser = _sbioser = _stateser = _soffser = _savfser
    = _sdataser = _ssoftser = _swatser = _sprotoser = _sdiagser = 0;
    first = true;
    _softload = false;
    ss.str("");
    //  1
    _logstart = "\tLogging\n\t\tStart: Not started(" + _Name + ")\n";
    _logcom = "\t\tCompleted: Not completed(" + _Name + ")\n"
                + "\t\tElapsed Time: \n";
    //  2
    _datainitstart = "\tDatabaseInitialize\n\t\tStart: Not started("
                    + _Name + ")\n";
    _datainitcom = "\t\tCompleted: Not completed(" + _Name + ")\n"
                    + "\t\tElapsed Time: \n";
    //  3
    _messerstart = "\tMessagingService\n\t\tStart: Not started(" + _Name
                    + ")\n";
    _messercom = "\t\tCompleted: Not completed(" + _Name + ")\n"
                    + "\t\tElapsed Time: \n";
    //  4
    _heathst = "\tHealthMonitorService\n\t\tStart: Not started(" + _Name
                + ")\n";
    _heathco = "\t\tCompleted: Not completed(" + _Name + ")\n"
            + "\t\tElapsed Time: \n";
    //  5
    _perserst = "\tPersistence\n\t\tStart: Not started(" + _Name + ")\n";
    _perserco = "\t\tCompleted: Not completed(" + _Name + ")\n"
                + "\t\tElapsed Time: \n";
    //  6
    _sconserst = "\tConfigurationService\n\t\tStart: Not started(" + _Name
                + ")\n";
    _sconserco = "\t\tCompleted: Not completed(" + _Name + ")\n"
                + "\t\tElapsed Time: \n";
    //  7
    _slserst = "\tLandingPadService\n\t\tStart: Not started(" + _Name
                + ")\n";
    _slserco = "\t\tCompleted: Not completed(" + _Name + ")\n"
                + "\t\tElapsed Time: \n";
    //  8
    _sportconst = "\tPortConfigurationService\n\t\tStart: Not started("
                + _Name + ")\n";
    _sportconco = "\t\tCompleted: Not completed(" + _Name + ")\n"
                + "\t\tElapsed Time: \n";
    //  9
    _scserst = "\tCacheService\n\t\tStart: Not started(" + _Name + ")\n";
    _scserco = "\t\tCompleted: Not completed(" + _Name + ")\n"
            + "\t\tElapsed Time: \n";
    //  10
    _sthemserst = "\tThemingService\n\t\tStart: Not started(" + _Name + ")\n";
    _sthemserco = "\t\tCompleted: Not completed(" + _Name + ")\n"
            + "\t\tElapsed Time: \n";
    //  11
    _sstaserst = "\tStagingService\n\t\tStart: Not started(" + _Name + ")\n";
    _sstaserco = "\t\tCompleted: Not completed(" + _Name + ")\n"
            + "\t\tElapsed Time: \n";
    //  12
    _sdevserst = "\tDeviceIOService\n\t\tStart: Not started(" + _Name + ")\n";
    _sdevserco = "\t\tCompleted: Not completed(" + _Name + ")\n"
            + "\t\tElapsed Time: \n";
    //  13
    _sbellserst = "\tBellService\n\t\tStart: Not started(" + _Name + ")\n";
    _sbellserco = "\t\tCompleted: Not completed(" + _Name + ")\n"
            + "\t\tElapsed Time: \n";
    //  14
    _sgateserst = "\tGateService\n\t\tStart: Not started(" + _Name + ")\n";
    _sgateserco = "\t\tCompleted: Not completed(" + _Name + ")\n"
            + "\t\tElapsed Time: \n";
    //  15
    _sreadserst = "\tReaderDataService\n\t\tStart: Not started(" + _Name
            + ")\n";
    _sreadserco = "\t\tCompleted: Not completed(" + _Name + ")\n"
            + "\t\tElapsed Time: \n";
    //  16
    _sbioserst = "\tBiometricService\n\t\tStart: Not started(" + _Name + ")\n";
    _sbioserco = "\t\tCompleted: Not completed(" + _Name + ")\n"
            + "\t\tElapsed Time: \n";
    //  17
    _stateserst = "\tStateManager\n\t\tStart: Not started(" + _Name + ")\n";
    _stateserco = "\t\tCompleted: Not completed(" + _Name + ")\n"
            + "\t\tElapsed Time: \n";
    //  18
    _soffserst = "\tOfflineSmartviewService\n\t\tStart: Not started(" + _Name
            + ")\n";
    _soffserco = "\t\tCompleted: Not completed(" + _Name + ")\n"
            + "\t\tElapsed Time: \n";
    //  19
    _savfserst = "\tAVFeedbackService\n\t\tStart: Not started(" + _Name
                + ")\n";
    _savfserco = "\t\tCompleted: Not completed(" + _Name + ")\n"
            + "\t\tElapsed Time: \n";
    //  20
    _sdataserst = "\tDatabaseThreads\n\t\tStart: Not started(" + _Name + ")\n";
    _sdataserco = "\t\tCompleted: Not completed(" + _Name + ")\n"
            + "\t\tElapsed Time: \n";
    //  21
    _ssoftserst = "\tSoftLoadService\n\t\tStart: Not started(" + _Name + ")\n";
    _ssoftserco = "\t\tCompleted: Not completed(" + _Name + ")\n"
            + "\t\tElapsed Time: \n";
    //  22
    _swatserst = "\tWATCHDOG\n\t\tStart: Not started(" + _Name + ")\n";
    _swatserco = "\t\tCompleted: Not completed(" + _Name + ")\n"
            + "\t\tElapsed Time: \n";
    //  23
    _sprotoserst = "\tProtocolService\n\t\tStart: Not started(" + _Name + ")\n";
    _sprotoserco = "\t\tCompleted: Not completed(" + _Name + ")\n"
            + "\t\tElapsed Time: \n";
    //  24
    _sdiagserst = "\tDiagnosticsService\n\t\tStart: Not started(" + _Name
            + ")\n";
    _sdiagserco = "\t\tCompleted: Not completed(" + _Name + ")\n"
            + "\t\tElapsed Time: \n";

    //  Softload
    _softloadstart = "";
    _softloador = "";
    _softloadnew = "";
    _softloadtime = "";
    _softloadelap = "";
}

void Kronos::update(int name, int check, const std::string line,
                                    const std::string _time) {
    switch (name) {
        case 1:
            if (check == 1) {
                // _logstart = "";
                _logstart = "\tLogging\n\t\tStart: " + line + "(" + _Name
                            + ")\n";
                // Check failed flag
                _logging == 1 ? _logging = 1 : _logging++;
            } else if (check == 2) {
               // _logcom = "";
                _logcom = "\t\tCompleted: " + line + "(" + _Name + ")\n"
                        + "\t\tElapsed Time: " + _time + "\n";
                _logging++;
            }
            break;

        case 2:
            if (check == 1) {
                // _datainitstart = "";
                _datainitstart = "\tDatabaseInitialize\n\t\tStart: " + line
                                + "(" + _Name + ")\n";
                // Check failed flag
                _datainit == 1 ? _datainit = 1 : _datainit++;
            } else if (check == 2) {
                // _datainitcom = "";
                _datainitcom = "\t\tCompleted: " + line + "(" + _Name + ")\n"
                                + "\t\tElapsed Time: " + _time + "\n";
                _datainit++;
            }
            break;

        case 3:
            if (check == 1) {
               // _messerstart = "";
                _messerstart = "\tMessagingService\n\t\tStart: " + line + "("
                            + _Name + ")\n";
                // Check failed flag
                _messer == 1 ? _messer = 1 : _messer++;
            } else if (check == 2) {
               // _messercom = "";
                _messercom = "\t\tCompleted: " + line + "(" + _Name + ")\n"
                            + "\t\tElapsed Time: " + _time + "\n";
                _messer++;
            }
            break;

        case 4:
            if (check == 1) {
               // _heathst = "";
                _heathst = "\tHealthMonitorService\n\t\tStart: " + line + "("
                            + _Name + ")\n";
                // Check failed flag
                _health == 1 ? _health = 1 : _health++;
            } else if (check == 2) {
               // _heathco = "";
                _heathco = "\t\tCompleted: " + line + "(" + _Name + ")\n"
                            + "\t\tElapsed Time: " + _time + "\n";
                _health++;
            }
            break;

        case 5:
            if (check == 1) {
               // _perserst = "";
                _perserst = "\tPersistence\n\t\tStart: " + line + "(" + _Name
                            + ")\n";
                // Check failed flag
                _sperser == 1 ? _sperser = 1 : _sperser++;
            } else if (check == 2) {
               // _perserco = "";
                _perserco = "\t\tCompleted: " + line + "(" + _Name + ")\n"
                            + "\t\tElapsed Time: " + _time + "\n";
                _sperser++;
            }
            break;

        case 6:
            if (check == 1) {
               // _sconserst = "";
                _sconserst = "\tConfigurationService\n\t\tStart: " + line
                            + "(" + _Name + ")\n";
                // Check failed flag
                _sconser == 1 ? _sconser = 1 : _sconser++;
            } else if (check == 2) {
               // _sconserco = "";
                _sconserco = "\t\tCompleted: " + line + "(" + _Name + ")\n"
                            + "\t\tElapsed Time: " + _time + "\n";
                _sconser++;
            }
            break;

        case 7:
            if (check == 1) {
               // _slserst = "";
                _slserst = "\tLandingPadService\n\t\tStart: " + line + "("
                        + _Name + ")\n";
                // Check failed flag
                _slser == 1 ? _slser = 1 : _slser++;
            } else if (check == 2) {
               // _slserco = "";
                _slserco = "\t\tCompleted: " + line + "(" + _Name + ")\n"
                        + "\t\tElapsed Time: " + _time + "\n";
                _slser++;
            }
            break;

        case 8:
            if (check == 1) {
               // _sportconst = "";
                _sportconst = "\tPortConfigurationService\n\t\tStart: " + line
                            + "(" + _Name + ")\n";
                // Check failed flag
                _sportcon == 1 ? _sportcon = 1 : _sportcon++;
            } else if (check == 2) {
               // _sportconco = "";
                _sportconco = "\t\tCompleted: " + line + "(" + _Name + ")\n"
                            + "\t\tElapsed Time: " + _time + "\n";
                _sportcon++;
            }
            break;

        case 9:
            if (check == 1) {
              //  _scserst = "";
                _scserst = "\tCacheService\n\t\tStart: " + line + "(" + _Name
                        + ")\n";
                // Check failed flag
                _scser == 1 ? _scser = 1 : _scser++;
            } else if (check == 2) {
               // _scserco = "";
                _scserco = "\t\tCompleted: " + line + "(" + _Name + ")\n"
                        + "\t\tElapsed Time: " + _time + "\n";
                _scser++;
            }
            break;

        case 10:
            if (check == 1) {
               // _sthemserst = "";
                _sthemserst = "\tThemingService\n\t\tStart: " + line + "("
                        + _Name + ")\n";
                // Check failed flag
                _sthemser == 1 ? _sthemser = 1 : _sthemser++;
            } else if (check == 2) {
               // _sthemserco = "";
                _sthemserco = "\t\tCompleted: " + line + "(" + _Name + ")\n"
                        + "\t\tElapsed Time: " + _time + "\n";
                _sthemser++;
            }
            break;

        case 11:
            if (check == 1) {
              //  _sstaserst = "";
                _sstaserst = "\tStagingService\n\t\tStart: " + line + "("
                        + _Name + ")\n";
                // Check failed flag
                _sstaser == 1 ? _sstaser = 1 : _sstaser++;
            } else if (check == 2) {
               // _sstaserco = "";
                _sstaserco = "\t\tCompleted: " + line + "(" + _Name + ")\n"
                        + "\t\tElapsed Time: " + _time + "\n";
                _sstaser++;
            }
            break;

        case 12:
            if (check == 1) {
              //  _sdevserst = "";
                _sdevserst = "\tDeviceIOService\n\t\tStart: " + line + "("
                        + _Name + ")\n";
                // Check failed flag
                _sdevser == 1 ? _sdevser = 1 : _sdevser++;
            } else if (check == 2) {
              //  _sdevserco = "";
                _sdevserco = "\t\tCompleted: " + line + "(" + _Name + ")\n"
                        + "\t\tElapsed Time: " + _time + "\n";
                _sdevser++;
            }
            break;

        case 13:
            if (check == 1) {
             //   _sbellserst = "";
                _sbellserst = "\tBellService\n\t\tStart: " + line + "("
                        + _Name + ")\n";
                // Check failed flag
                _sbellser == 1 ? _sbellser = 1 : _sbellser++;
            } else if (check == 2) {
              //  _sbellserco = "";
                _sbellserco = "\t\tCompleted: " + line + "(" + _Name + ")\n"
                        + "\t\tElapsed Time: " + _time + "\n";
                _sbellser++;
            }
            break;

        case 14:
            if (check == 1) {
              //  _sgateserst = "";
                _sgateserst = "\tGateService\n\t\tStart: " + line + "("
                        + _Name + ")\n";
                // Check failed flag
                _sgateser == 1 ? _sgateser = 1 : _sgateser++;
            } else if (check == 2) {
              //  _sgateserco = "";
                _sgateserco = "\t\tCompleted: " + line + "(" + _Name + ")\n"
                        + "\t\tElapsed Time: " + _time + "\n";
                _sgateser++;
            }
            break;

        case 15:
            if (check == 1) {
              //  _sreadserst = "";
                _sreadserst = "\tReaderDataService\n\t\tStart: " + line + "("
                        + _Name + ")\n";
                // Check failed flag
                _sreadser == 1 ? _sreadser = 1 : _sreadser++;
            } else if (check == 2) {
             //   _sreadserco = "";
                _sreadserco = "\t\tCompleted: " + line + "(" + _Name + ")\n"
                        + "\t\tElapsed Time: " + _time + "\n";
                _sreadser++;
            }
            break;

        case 16:
            if (check == 1) {
              //  _sbioserst = "";
                _sbioserst = "\tBiometricService\n\t\tStart: " + line + "("
                        + _Name + ")\n";
                // Check failed flag
                _sbioser == 1 ? _sbioser = 1 : _sbioser++;
            } else if (check == 2) {
             //   _sbioserco = "";
                _sbioserco = "\t\tCompleted: " + line + "(" + _Name + ")\n"
                        + "\t\tElapsed Time: " + _time + "\n";
                _sbioser++;
            }
            break;

        case 17:
            if (check == 1) {
             //   _stateserst = "";
                _stateserst = "\tStateManager\n\t\tStart: " + line + "("
                        + _Name + ")\n";
                // Check failed flag
                _stateser == 1 ? _stateser = 1 : _stateser++;
            } else if (check == 2) {
             //   _stateserco = "";
                _stateserco = "\t\tCompleted: " + line + "(" + _Name + ")\n"
                        + "\t\tElapsed Time: " + _time + "\n";
                _stateser++;
            }
            break;

        case 18:
            if (check == 1) {
             //   _soffserst = "";
                _soffserst = "\tOfflineSmartviewService\n\t\tStart: " + line
                            + "(" + _Name + ")\n";
                // Check failed flag
                _soffser == 1 ? _soffser = 1 : _soffser++;
            } else if (check == 2) {
             //   _soffserco = "";
                _soffserco = "\t\tCompleted: " + line + "(" + _Name + ")\n"
                            + "\t\tElapsed Time: " + _time + "\n";
                _soffser++;
            }
            break;

        case 19:
            if (check == 1) {
             //   _savfserst = "";
                _savfserst = "\tAVFeedbackService\n\t\tStart: " + line + "("
                            + _Name + ")\n";
                // Check failed flag
                _savfser == 1 ? _savfser = 1 : _savfser++;
            } else if (check == 2) {
              //  _savfserco = "";
                _savfserco = "\t\tCompleted: " + line + "(" + _Name + ")\n"
                            + "\t\tElapsed Time: " + _time + "\n";
                _savfser++;
            }
            break;

        case 20:
            if (check == 1) {
             //   _sdataserst = "";
                _sdataserst = "\tDatabaseThreads\n\t\tStart: " + line + "("
                            + _Name + ")\n";
                // Check failed flag
                _sdataser == 1 ? _sdataser = 1 : _sdataser++;
            } else if (check == 2) {
              //  _sdataserco = "";
                _sdataserco = "\t\tCompleted: " + line + "(" + _Name + ")\n"
                            + "\t\tElapsed Time: " + _time + "\n";
                _sdataser++;
            }
            break;

        case 21:
            if (check == 1) {
            //    _ssoftserst = "";
                _ssoftserst = "\tSoftLoadService\n\t\tStart: " + line + "("
                            + _Name + ")\n";
                // Check failed flag
                _ssoftser == 1 ? _ssoftser = 1 : _ssoftser++;
            } else if (check == 2) {
              //  _ssoftserco = "";
                _ssoftserco = "\t\tCompleted: " + line + "(" + _Name + ")\n"
                            + "\t\tElapsed Time: " + _time + "\n";
                _ssoftser++;
            }
            break;

        case 22:
            if (check == 1) {
           //     _swatserst = "";
                _swatserst = "\tWATCHDOG\n\t\tStart: " + line + "(" + _Name
                            + ")\n";
                // Check failed flag
                _swatser == 1 ? _swatser = 1 : _swatser++;
            } else if (check == 2) {
           //     _swatserco = "";
                _swatserco = "\t\tCompleted: " + line + "(" + _Name + ")\n"
                            + "\t\tElapsed Time: " + _time + "\n";
                _swatser++;
            }
            break;

        case 23:
            if (check == 1) {
           //     _sprotoserst = "";
                _sprotoserst = "\tProtocolService\n\t\tStart: " + line + "("
                            + _Name + ")\n";
                // Check failed flag
                _sprotoser == 1 ? _sprotoser = 1 : _sprotoser++;
            } else if (check == 2) {
          //      _sprotoserco = "";
                _sprotoserco = "\t\tCompleted: " + line + "(" + _Name + ")\n"
                            + "\t\tElapsed Time: " + _time + "\n";
                _sprotoser++;
            }
            break;

        case 24:
            if (check == 1) {
             //   _sdiagserst = "";
                _sdiagserst = "\tDiagnosticsService\n\t\tStart: " + line + "("
                            + _Name + ")\n";
                // Check failed flag
                _sdiagser == 1 ? _sdiagser = 1 : _sdiagser++;
            } else if (check == 2) {
             //   _sdiagserco = "";
                _sdiagserco = "\t\tCompleted: " + line + "(" + _Name + ")\n"
                            + "\t\tElapsed Time: " + _time + "\n";
                _sdiagser++;
            }
            break;

        case 25:
            if (check == 1) {
                _softloadstart = line + "(" + _Name + ") : " + _time
                            + " Softload Start\n";
                _softload = true;
            } else if (check == 2) {
                _softloadnew = "\tNew version ==> " + _time + "\n";
            } else if (check == 3) {
                _softloador = "\tOriginal version ==> " + _time + "\n";
            } else if (check == 4) {
                _softloadtime = line + "(" + _Name + ") : " + _time
                            + " Softload Completed\n";
            } else if (check == 5) {
                _softloadelap = "\tElapsed time (sec) ==> " + line + "\n";
            }
            break;

        default:
            // Code
            break;
    }
}


std::string Kronos::getStr(void) {
    ss << "Services\n";
    ss << _logstart << _logcom << _datainitstart << _datainitcom
        << _messerstart << _messercom << _heathst << _heathco
        << _perserst << _perserco << _sconserst << _sconserco
        << _slserst << _slserco << _sportconst << _sportconco
        << _scserst << _scserco << _sthemserst << _sthemserco
        << _sstaserst << _sstaserco << _sdevserst << _sdevserco
        << _sbellserst <<_sbellserco << _sgateserst << _sgateserco
        << _sreadserst << _sreadserco << _sbioserst << _sbioserco
        << _stateserst << _stateserco << _soffserst << _soffserco
        << _savfserst << _savfserco << _sdataserst << _sdataserco
        << _ssoftserst << _ssoftserco << _swatserst << _swatserco
        << _sprotoserst << _sprotoserco << _sdiagserst << _sdiagserco;

    if (_logging < 2) {
        if (first) {
            ss << "\t*** Services not successfully started: Logging";
            first = false;
        } else {
            ss << ", Logging";
        }
    }

    if (_datainit < 2) {
        if (first) {
            ss << "\t*** Services not successfully started: DatabaseInitialize";
            first = false;
        } else {
            ss << ", DatabaseInitialize";
        }
    }

    if (_messer < 2) {
        if (first) {
            ss << "\t*** Services not successfully started: MessagingService";
            first = false;
        } else {
            ss << ", MessagingService";
        }
    }

    if (_health < 2) {
        if (first) {
            ss << "\t*** Services not successfully started:"
                << "HealthMonitorService";
            first = false;
        } else {
            ss << ", HealthMonitorService";
        }
    }

    if (_sperser < 2) {
        if (first) {
            ss << "\t*** Services not successfully started: Persistence";
            first = false;
        } else {
            ss << ", Persistence";
        }
    }

    if (_sconser < 2) {
        if (first) {
            ss << "\t*** Services not successfully started:"
                << "ConfigurationService";
            first = false;
        } else {
            ss << ", ConfigurationService";
        }
    }

    if (_slser < 2) {
        if (first) {
            ss << "\t*** Services not successfully started: LandingPadService";
            first = false;
        } else {
            ss << ", LandingPadService";
        }
    }

    if (_sportcon < 2) {
        if (first) {
            ss << "\t*** Services not successfully started:"
                << "PortConfigurationService";
            first = false;
        } else {
            ss << ", PortConfigurationService";
        }
    }

    if (_scser < 2) {
        if (first) {
            ss << "\t*** Services not successfully started: CacheService";
            first = false;
        } else {
            ss << ", CacheService";
        }
    }

    if (_sthemser < 2) {
        if (first) {
            ss << "\t*** Services not successfully started: ThemingService";
            first = false;
        } else {
            ss << ", ThemingService";
        }
    }

    if (_sstaser < 2) {
        if (first) {
            ss << "\t*** Services not successfully started: StagingService";
            first = false;
        } else {
            ss << ", StagingService";
        }
    }

    if (_sdevser < 2) {
        if (first) {
            ss << "\t*** Services not successfully started: DeviceIOService";
            first = false;
        } else {
            ss << ", DeviceIOService";
        }
    }

    if (_sbellser < 2) {
        if (first) {
            ss << "\t*** Services not successfully started: BellService";
            first = false;
        } else {
            ss << ", BellService";
        }
    }

    if (_sgateser < 2) {
        if (first) {
            ss << "\t*** Services not successfully started: GateService";
            first = false;
        } else {
            ss << ", GateService";
        }
    }

    if (_sreadser < 2) {
        if (first) {
            ss << "\t*** Services not successfully started: ReaderDataService";
            first = false;
        } else {
            ss << ", ReaderDataService";
        }
    }

    if (_sbioser < 2) {
        if (first) {
            ss << "\t*** Services not successfully started: BiometricService";
            first = false;
        } else {
            ss << ", BiometricService";
        }
    }

    if (_stateser < 2) {
        if (first) {
            ss << "\t*** Services not successfully started: StateManager";
            first = false;
        } else {
            ss << ", StateManager";
        }
    }

    if (_soffser < 2) {
        if (first) {
            ss << "\t*** Services not successfully started:"
                << " OfflineSmartviewService";
            first = false;
        } else {
            ss << ", OfflineSmartviewService";
        }
    }

    if (_savfser < 2) {
        if (first) {
            ss << "\t*** Services not successfully started: AVFeedbackService";
            first = false;
        } else {
            ss << ", AVFeedbackService";
        }
    }

    if (_sdataser < 2) {
        if (first) {
            ss << "\t*** Services not successfully started: DatabaseThreads";
            first = false;
        } else {
            ss << ", DatabaseThreads";
        }
    }

    if (_ssoftser < 2) {
        if (first) {
            ss << "\t*** Services not successfully started: SoftLoadService";
            first = false;
        } else {
            ss << ", SoftLoadService";
        }
    }

    if (_swatser < 2) {
        if (first) {
            ss << "\t*** Services not successfully started: WATCHDOG";
            first = false;
        } else {
            ss << ", WATCHDOG";
        }
    }

    if (_sprotoser < 2) {
        if (first) {
            ss << "\t*** Services not successfully started: ProtocolService";
            first = false;
        } else {
            ss << ", ProtocolService";
        }
    }

    if (_sdiagser < 2) {
        if (first) {
            ss << "\t*** Services not successfully started: DiagnosticsService";
            first = false;
        } else {
            ss << ", DiagnosticsService";
        }
    }

    ss << "\n";

    return ss.str();
}

std::string Kronos::getsl(void) {
    std::stringstream a;
    if (_softload) {
        a << "=== Softload ===\n"
        << _softloadstart << _softloador << _softloadnew
        << _softloadelap << _softloadtime;
    }
    // std::cout << a.str();
    return a.str();
}
