//
//  NLAAutomatDeviceData.h
//  AutomatLibApp
//
//  Created by Emil Lundgren on 2015-08-10.
//  Copyright (c) 2015 Emil Lundgren. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NLAConstants.h"

/**
 *  Baseclass for all data representing incoming data from an 
 *  Automat device.
 */
@interface NLAAutomatDeviceData : NSObject

/**
 *  This timestamp represents the time in milliseconds since the Automat 
 *  device was connected.
 */
@property (nonatomic, readonly) NSTimeInterval timestamp;

@end
