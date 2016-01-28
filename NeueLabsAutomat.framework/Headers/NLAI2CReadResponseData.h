//
//  NLAI2CReadResponseData.h
//  AutomatLibApp
//
//  Created by Emil Lundgren on 2015-08-14.
//  Copyright (c) 2015 Emil Lundgren. All rights reserved.
//

#import "NLAI2CData.h"


/**
 *  When an I2C read command is performed, you pass in a handler block
 *  that will be invoked passing in an instance of this class containing
 *  the I2C responses.
 */
@interface NLAI2CReadResponseData : NLAI2CData

/**
 *  An array of NSNumbers representing the responses.
 */
@property (nonatomic, strong, readonly) NSArray *responses;
/**
 *  The response length in bytes.
 */
@property (nonatomic, readonly) uint8_t responseLength;

@end
