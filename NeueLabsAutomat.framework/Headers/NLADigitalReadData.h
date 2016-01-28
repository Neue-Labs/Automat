//
//  NLADigitalReadData.h
//  AutomatLibApp
//
//  Created by Emil Lundgren on 2015-09-09.
//  Copyright (c) 2015 Emil Lundgren. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NLAAutomatDeviceData.h"


/**
 *  Instances of this class will be passed to the handler block
 *  invoked when being notified from the Baseboard of digital in data.
 */
@interface NLADigitalReadData : NLAAutomatDeviceData

/**
 *  The input states for all the digital ports.
 */
@property (nonatomic, readonly) uint16_t inputStates;
/**
 *  This array contain strings with the ports received
 *  in the digital in notification on the board.
 */
@property (nonatomic, readonly) NSArray * highPorts;

/**
 *  Check the signal for a given port.
 *
 *  @param port
 *
 *  @return the signal value HIGH or LOW.
 */
-(NLADigitalSignal) signalForPort:(NLABaseBoardIOPort) port;

@end
