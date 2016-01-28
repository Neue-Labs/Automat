//
//  NLAAutomatDevice.h
//  AutomatLibApp
//
//  Created by Emil Lundgren on 2015-08-10.
//  Copyright (c) 2015 Emil Lundgren. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NLAConstants.h"


/**
 *  This is the base class for all classes that handles the communication with a connected
 *  Automat device.
 */
@interface NLAAutomatDevice : NSObject <CBPeripheralDelegate>

/**
 *  Contains info about hardware and firmware version for this connected device.
 */
@property (nonatomic, strong, readonly) NSDictionary *deviceInfo;


-(void) readRSSIWithHandler:(NLARSSIHandler) rssiHandler;


/**
 *  Reboots the Automat device into BIOS mode where the firmware can be updated.
 */
-(void) rebootDeviceInBIOSMode;
/**
 *  When a device runs in BIOS mode a new firmware can be uploaded.
 *
 *  @param firmwarePath the path to the firmware file.
 */
-(void) updateFirmwareWithFileAtPath:(NSString *)firmwarePath withHandler:(NLAOADUpdateStatusHandler) handler;

@end
