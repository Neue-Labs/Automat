//
//  NLAI2CReadData.h
//  AutomatLibApp
//
//  Created by Emil Lundgren on 2015-08-14.
//  Copyright (c) 2015 Emil Lundgren. All rights reserved.
//

#import "NLAI2CData.h"

@interface NLAI2CReadData : NLAI2CData

/**
 *  Response length in bytes
 */
@property (nonatomic, readonly) uint8_t responseLength;

@end
