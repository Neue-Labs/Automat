//
//  NLAMotionFeaturesData.h
//  AutomatLibApp
//
//  Created by Emil Lundgren on 2015-10-13.
//  Copyright © 2015 Emil Lundgren. All rights reserved.
//

#import "NLAAutomatDeviceData.h"

@interface NLAMotionFeaturesData : NLAAutomatDeviceData

@property (nonatomic, readonly) BOOL isWakeup;
@property (nonatomic, readonly) NSInteger nrOfTaps;
@property (nonatomic, readonly) BOOL isTilt;
@property (nonatomic, readonly) NSInteger nrOfSteps;
@property (nonatomic, readonly) BOOL isFreeFall;

@end
