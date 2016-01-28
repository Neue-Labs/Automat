//
//  NLAI2CMutableWriteData.h
//  AutomatLibApp
//
//  Created by Emil Lundgren on 2015-08-17.
//  Copyright (c) 2015 Emil Lundgren. All rights reserved.
//

#import "NLAI2CWriteData.h"

@interface NLAI2CMutableWriteData : NLAI2CWriteData


/**
 *  Initialize with an 8-bit value representing the i2c address to write to.
 *
 *  @param address
 *
 *  @return An instance of this class
 */
-(instancetype) initWithAddress:(uint8_t) address;

/**
 *  Add an i2c write command.
 *
 *  @param command An 8-bit value
 */
-(void) addI2CCommand:(uint8_t) command;
/**
 *  You can add an array of commands.
 *
 *  @param commands     A uint8_t c array of commands.
 *  @param nrOfCommands Number of elements in the array you passed in.
 */
-(void) addI2CCommands:(uint8_t *) commands count:(NSInteger) nrOfCommands;

/**
 *  This is set by the framework when it creates a write data object
 *  to pass to the handler when performing a write.
 *
 *  @param timestamp
 */
-(void) setTimestamp:(NSTimeInterval) timestamp;

@end
