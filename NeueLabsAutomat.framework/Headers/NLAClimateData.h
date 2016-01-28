//
//  NLAClimateData.h
//  AutomatLibApp
//
//  Created by Emil Lundgren on 2015-08-14.
//  Copyright (c) 2015 Emil Lundgren. All rights reserved.
//

#import "NLAAutomatDeviceData.h"

@interface NLAClimateData : NLAAutomatDeviceData

@property (nonatomic, strong, readonly) NSNumber *temperature;
@property (nonatomic, strong, readonly) NSNumber *humidity;

@end
