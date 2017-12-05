// Copyright Chuong Vu
// Filename: kronos_parse.hpp
#include <string>
#include <sstream>  // Required for stringstreams

class Kronos {
 public:
    explicit Kronos(std::string input);
    std::string getStr(void);
    std::string getsl(void);
    void update(int name, int check, const std::string line,
                                                const std::string time);
    void reset(void);

 private:
    std::stringstream ss;  //  hold the output string
    std::string _Name;  // device name

    // 24 steps
    std::string _logstart, _logcom, _datainitstart, _datainitcom, _messerstart,
    _messercom, _heathst, _heathco, _perserst, _perserco, _sconserst,
    _sconserco, _slserst, _slserco, _sportconst, _sportconco, _scserst,
    _scserco, _sthemserst, _sthemserco, _sstaserst, _sstaserco, _sdevserst,
    _sdevserco, _sbellserst, _sbellserco, _sgateserst, _sgateserco, _sreadserst,
    _sreadserco, _sbioserst, _sbioserco, _stateserst, _stateserco, _soffserst,
    _soffserco, _savfserst, _savfserco, _sdataserst, _sdataserco, _ssoftserst,
    _ssoftserco, _swatserst, _swatserco, _sprotoserst, _sprotoserco,
    _sdiagserst, _sdiagserco;

    //  for softload
    std::string _softloadstart, _softloador, _softloadnew, _softloadtime,
    _softloadelap;

    int _logging, _datainit, _messer, _health, _sperser, _sconser,
    _slser, _sportcon, _scser, _sthemser, _sstaser, _sdevser, _sbellser,
    _sgateser, _sreadser, _sbioser, _stateser, _soffser, _savfser, _sdataser,
    _ssoftser, _swatser, _sprotoser, _sdiagser;
    bool first;  // first value use to check first failed
    bool _softload;  //  check softload start or not.
};
