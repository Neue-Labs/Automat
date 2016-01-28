//
//  NLAI2CMutableReadData.h
//  AutomatLibApp
//
//  Created by Emil Lundgren on 2015-08-17.
//  Copyright (c) 2015 Emil Lundgren. All rights reserved.
//

#import "NLAI2CReadData.h"

@interface NLAI2CMutableReadData : NLAI2CReadData

/**
 *  Create an NLAI2CMutableReadData object with the address, an 8-bit value and
 *  the expected response length in bytes.
 *
 *  @param address
 *  @param responseLength
 *
 *  @return An instance of NLAI2CMutableReadData
 */
-(instancetype) initWithAddress:(uint8_t) address expectedResponseLength:(uint8_t) responseLength;

/**
 *  Add an i2c command.
 *
 *  @param command Must be an 8 bit value.
 */
-(void) addI2CCommand:(uint8_t) command;
/**
 *  You can create an array of commands and pass in.
 *
 *  @param commands A uint_8t c array.
 *  @param nrOfCommands This is number of elements in the commands array passed in
 */
-(void) addI2CCommands:(uint8_t *) commands count:(NSInteger) nrOfCommands;


@end
