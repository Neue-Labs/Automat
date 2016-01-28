//
//  NLADigitalWritePattern.h
//  AutomatLibApp
//
//  Created by Emil Lundgren on 2015-09-14.
//  Copyright (c) 2015 Emil Lundgren. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NLAConstants.h"


@interface NLADigitalBlinkSequence : NSObject

/**
 *  The digital ports that the sequence will be written to.
 */
@property (nonatomic, readonly) uint16_t ports;
/**
 *  Sets the number of blinks from 0x00 to 0xFE.
 *  Setting it to 0xFF means blink forever.
 */
@property (nonatomic, assign) uint8_t nrOfBlinks;
/**
 *  Set the output ration in %, 0 - 100.
 *  Ratio of on and off time for the period.
 *  The value 50 means 50% on and 50% off.
 */
@property (nonatomic, assign) uint8_t outputRatio;
/**
 *  Blink period in milliseconds.
 */
@property (nonatomic, assign) uint16_t outputPeriod;

/**
 *  Add digital port that this blink sequence will be written to.
 *  Make sure to set it using the NLAAutomatDevice sublass to OUTPUT
 *  and write the settings to the board.
 *
 *  @param port 
 */
-(void) addDigitalPort:(NLABaseBoardIOPort) port;

@end
