//
//  NLAOADUpdateStatus.h
//  AutomatLibApp
//
//  Created by Emil Lundgren on 2015-10-08.
//  Copyright © 2015 Emil Lundgren. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface NLAOADUpdateStatus : NSObject

@property (nonatomic, strong) NSNumber *progress;
@property (nonatomic, assign) NSTimeInterval timeRemaining;
@property (nonatomic, strong) NSString *status;

@end
