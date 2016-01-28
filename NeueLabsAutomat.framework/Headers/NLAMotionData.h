//
//  NLAMotionData.h
//  AutomatLibApp
//
//  Created by Emil Lundgren on 2015-09-03.
//  Copyright (c) 2015 Emil Lundgren. All rights reserved.
//

#import "NLAAutomatDeviceData.h"

@interface NLAMotionData : NLAAutomatDeviceData


/**
 *  A struct containing the raw acceleration data for x,y,z
 *  from a connected Automat device
 */
@property (nonatomic, readonly) NLAAcceleration acceleration;
/**
 *  A struct containing the raw gyroscope data for x,y,z from
 *  a connected Automat device.
 */
@property (nonatomic, readonly) NLARotationSpeed rotationSpeed;
/**
 *  A struct containing the euler angles, roll, pitch and yaw
 *  of the orientation for a connected Automat device.
 *  It's calculated using the gyroscope and accelerometer data.
 *  @warning You need to calibrate the gyro before this data is
 *  available.
 */
@property (nonatomic, readonly) NLAOrientationEuler orientation;
/**
 *  Like @see orientation but instead the orientation expressed as
 *  a quaternion. This struct contains the double values q1,q2,q3,q4.
 *  q1 - q3 is the orientation and q4 the control value for the quaternion.
 */
@property (nonatomic, readonly) NLAQuaternion quaternion;
/**
 *  The angular relationship between the given body and inertial axis.
 *  @see NLABaseboard angularRelationshipBodyAxis:intertialAxis: to set the axes.
 */
@property (nonatomic, readonly) double angularRelationship;



@end
