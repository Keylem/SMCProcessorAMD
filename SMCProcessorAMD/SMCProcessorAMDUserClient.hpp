//
//  SMCProcessorAMDUserClient.hpp
//  SMCProcessorAMD
//
//  Created by Qi HaoYan on 2/4/20.
//  Copyright © 2020 Qi HaoYan. All rights reserved.
//

#ifndef SMCProcessorAMDUserClient_hpp
#define SMCProcessorAMDUserClient_hpp

//Support for macOS 10.13
#include <Library/LegacyIOService.h>
#include "LegacyHeaders/LegacyIOUserClient.h"

#include <sys/proc.h>

//#include <IOKit/IOService.h>
//#include <IOKit/IOUserClient.h>
//#include <IOKit/IOLib.h>

#include "SMCProcessorAMD.hpp"

extern "C" {
    proc_t get_bsdtask_info(task_t t);
};



class SMCProcessorAMDUserClient : public IOUserClient
{

    OSDeclareDefaultStructors(SMCProcessorAMDUserClient)
    
      
public:
    
    bool initWithTask(task_t owningTask, void *securityToken, UInt32 type, OSDictionary *properties) override;
    
    // IOUserClient methods
    virtual void stop(IOService* provider) override;
    virtual bool start(IOService* provider) override;
    
    
    
protected:
    
    SMCProcessorAMD *fProvider;
    void *token;
    
    bool hasPrivilege();
    
    // KPI for supporting access from both 32-bit and 64-bit user processes beginning with Mac OS X 10.5.
    virtual IOReturn externalMethod(uint32_t selector, IOExternalMethodArguments* arguments,
                                    IOExternalMethodDispatch* dispatch, OSObject* target, void* reference) override;
    
    
    char taskProcessBinaryName[32]{};
};

#endif
