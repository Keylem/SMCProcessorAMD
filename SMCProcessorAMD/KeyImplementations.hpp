//
//  KeyImplementations.hpp
//  SMCProcessorAMD
//
//  Created by Qi HaoYan on 2/12/20.
//  Copyright © 2020 Qi HaoYan. All rights reserved.
//

#ifndef KeyImplementations_hpp
#define KeyImplementations_hpp

#include <VirtualSMCSDK/kern_vsmcapi.hpp>
#include "SMCProcessorAMD.hpp"

class SMCProcessorAMD;


class AMDSupportVsmcValue : public VirtualSMCValue {
protected:
    SMCProcessorAMD *provider;
    size_t package;
    size_t core;
public:
    AMDSupportVsmcValue(SMCProcessorAMD *provider, size_t package, size_t core=0) : provider(provider), package(package), core(core) {}
};


class TempPackage : public AMDSupportVsmcValue { using AMDSupportVsmcValue::AMDSupportVsmcValue; protected: SMC_RESULT readAccess() override; };
class TempCore    : public AMDSupportVsmcValue { using AMDSupportVsmcValue::AMDSupportVsmcValue; protected: SMC_RESULT readAccess() override; };

class EnergyPackage: public AMDSupportVsmcValue
{ using AMDSupportVsmcValue::AMDSupportVsmcValue; protected: SMC_RESULT readAccess() override; };

#endif /* KeyImplementations_hpp */
