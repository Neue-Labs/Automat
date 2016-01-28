//
//  NLAI2CData.h
//  AutomatLibApp
//
//  Created by Emil Lundgren on 2015-08-14.
//  Copyright (c) 2015 Emil Lundgren. All rights reserved.
//

#import "NLAAutomatDeviceData.h"

@interface NLAI2CData : NLAAutomatDeviceData

@property (nonatomic, readonly) uint8_t i2cAddress;
@property (nonatomic, readonly, strong) NSArray *commands;

@end
