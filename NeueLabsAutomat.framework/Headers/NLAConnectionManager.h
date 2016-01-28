//
//  NLAConnectionManager.h
//  AutomatLibApp
//
//  Created by Emil Lundgren on 2015-08-03.
//  Copyright (c) 2015 Emil Lundgren. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NLAConstants.h"
#import "NLAAutomatDevice.h"

/**
 * This is were it all starts. You retreive a singleton instance of this class in order to start
 * scanning for Automat devices.
 * When a device is found a kAutomatDeviceDidConnectNotification is being posted through NSNotificationCenter.
 * The userInfo dictionary in the notification has a key called kAutomatDeviceIdentifier containing an NSString
 * with the UUID for the connected device. Use this UUID to retreive an instance of an NLAAutomatDevice subclass
 * which handles the connected device.
 * When a device is found, you can stop scanning in order to save battery power on the iOS device.
 */

@interface NLAConnectionManager : NSObject <CBCentralManagerDelegate, CBPeripheralDelegate>

@property (nonatomic, strong, readonly) NSArray *connectedAutomatDevices;
@property (nonatomic, strong, readonly) NSArray *rangingAutomatDevices;


/**
 *  Retreive the singleton instance of the NLAConnectionManager
 *
 *  @return The singleton instance
 */
+(instancetype) sharedConnectionManager;
/**
 *  Start scanning for Automat devices. If scanning allready is underway, nothing will happen.
 */
-(void) startScanningForAutomatDevices;
/**
 *  Stop scanning for Automat devices.
 */
-(void) stopScanningForAutomatDevices;

/**
 *  Retreive an instance of an NLAAutomatDevice subclass that handles the communication
 *  between the iOS device and the Automat device with the given identifier.
 *
 *  @param identifier The identifier (UUID) for an Automat device can be read in the kAutomatDeviceDidConnectNotification
 *  when a device is connected. In the userInfo dictionary of the notification object, retreive the NSString
 *  with the identifier using the key kAutomatDeviceIdentifier.
 *
 *  @return An object of an NLAAutomatDevice subclass.
 */
-(NLAAutomatDevice *) automatDeviceWithIdentifier:(NSString *) identifier;

-(void) connectToDeviceWithIdentifier:(NSString *) identifier;

-(void) disconnectDeviceWithIdentifier:(NSString *) identifier;

-(void) softwarePairDeviceWithIdentifier:(NSString *) identifier;

-(void) removeSoftwarePairingForDeviceWithIdentifier:(NSString *) identifier;




@end
