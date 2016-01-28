//
//  NLAConstants.h
//  AutomatLibApp
//
//  Created by Emil Lundgren on 2015-08-03.
//  Copyright (c) 2015 Emil Lundgren. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

@class NLAAutomatDeviceData;
@class NLADigitalReadData;
@class NLAI2CWriteData;
@class NLAI2CReadResponseData;
@class NLAOADUpdateStatus;
@class NLAMotionFeaturesData;

extern NSString *const kAutomatPeripheralStoppedAdvertisingNotification;
extern NSString *const kAutomatDeviceWasDiscoveredNotification;
extern NSString *const kAutomatDeviceDidConnectNotification;
extern NSString *const kAutomatDeviceDidDisconnectNotification;
extern NSString *const kAutomatDeviceErrorWhileConnectingNotification;
extern NSString *const kAutomatFailToConnectError;
extern NSString *const kAutomatDeviceReadyNotification;
extern NSString *const kAutomatDidDiscoverServiceNotification;
extern NSString *const kAutomatServiceUUIDs;
extern NSString *const kAutomatServiceForCharacteristicsUUID;
extern NSString *const kAutomatDidDiscoverCharacteristicNotification;
extern NSString *const kAutomatCharacteristicUUIDs;

extern NSString *const kAutomatDeviceType;
extern NSString *const kAutomatDeviceIdentifier;

extern NSString *const automatDeviceTypeBaseBoard;

extern NSString *const kOADStatusMessageUpdating;
extern NSString *const kOADStatusMessageFinishedUpdating;

extern NSString *const kBaseboardMotionSensorsServiceUUID;
extern NSString *const kBaseboardClimateServiceUUID;
extern NSString *const kBaseboardI2CServiceUUID;
extern NSString *const kBaseboardPortIOServiceUUID;



extern NSString *const kBlueToothDeviceInfoServiceUUID;
extern NSString *const manufacturerNameStringUUID;
extern NSString *const modelnumberStringUUID;
extern NSString *const serialNumberStringUUID;
extern NSString *const hardwareRevisionStringUUID;
extern NSString *const firmwareRevisionStringUUID;
extern NSString *const softwareRevisionStringUUID;

typedef void (^NLARSSIHandler)(NSNumber *RSSI, NSError *error);
typedef void (^NLASensorHandler)(NLAAutomatDeviceData *sensorData, NSError *error);
typedef void (^NLAGyroscopeCalibrationHandler)(NSNumber *progress, BOOL finished ,NSError *error);
typedef void (^NLAI2CWriteHandler)(NLAI2CWriteData *writeData, NSError *error);
typedef void (^NLAI2CReadHandler)(NLAI2CReadResponseData *responseData, NSError *error);
typedef void (^NLAMotionFeaturesHandler)(NLAMotionFeaturesData *motionFeaturesData, NSError *error);

typedef struct {double x; double y; double z; int16_t rawX; int16_t rawY; int16_t rawZ;} NLARotationSpeed;
typedef struct {double x; double y; double z; int16_t rawX; int16_t rawY; int16_t rawZ;} NLAAcceleration;
typedef struct {double roll; double pitch; double yaw;} NLAOrientationEuler;
typedef struct {double q1; double q2; double q3; double q4;} NLAQuaternion;
typedef struct {double x; double y; double z;} NLAInertialForces;

typedef enum NLAMotionSensorODRValue : uint8_t {
    NLAMotionPowerOff = 0x00,
    NLAMotionLowPowerMode13Hz = 0x01,
    NLAMotionLowPowerMode26Hz = 0x02,
    NLAMotionLowPowerMode52Hz = 0x03,
    NLAMotionNormalMode104Hz = 0x04,
    NLAMotionNormalMode208Hz = 0x05,
    NLAMotionHighPerformanceMode416Hz = 0x06,
    NLAMotionHighPerformanceMode833Hz = 0x07,
    NLAMotionHighPerformanceMode1666Hz = 0x08,
    NLAMotionHighPerformanceMode3332HzAccOnly = 0x09,
    NLAMotionHighPerformanceMode6664HzAccOnly = 0x10
} NLAMotionSensorODRValue;

typedef enum NLAMotionSensorFeature : uint8_t {
    NLAMotionFeatureAccGyro = 0x00,
    NLAMotionFeatureSingleTap = 0x01,
    NLAMotionFeatureDoubleTap = 0x02,
    NLAMotionFeatureFreeFall = 0x03,
    NLAMotionFeatureWakeUp = 0x04,
    NLAMotionFeatureStepCounter = 0x05,
    NLAMotionFeatureResetSteps = 0x06,
    NLAMotionFeatureTilt = 0x07
}NLAMotionSensorFeature;

typedef enum NLAGyroscopeRange : uint8_t {
    NLAGyroRange125DPS = 0x00,
    NLAGyroRange245DPS = 0x01,
    NLAGyroRange500DPS = 0x02,
    NLAGyroRange1000DPS = 0x03,
    NLAGyroRange2000DPS = 0x04,
    
}NLAGyroscopeRange;

typedef enum NLAAccelerometerRange : uint8_t {
    NLAAccRange2G = 0x00,
    NLAAccRange4G = 0x01,
    NLAAccRange8G = 0x02,
    NLAAccRange16G = 0x03,
    
} NLAAccelerometerRange;

typedef enum NLAErrorCodes : NSInteger {
    
    NLAErrorOADFailure = 0,

    
    
    
} NLAErrorCodes;

extern NSString *const NLAErrorDomain;

// ----------------------------------------
// PORT I/O
// ----------------------------------------


typedef NS_ENUM(NSInteger, NLABaseBoardIOPort) {
    NLABaseBoardIO1,
    NLABaseBoardIO2,
    NLABaseBoardIO3,
    NLABaseBoardIO4,
    NLABaseBoardIO5,
    NLABaseBoardIO6,
    NLABaseBoardIO7,
    NLABaseBoardIO8,
    NLABaseBoardIO9,
    NLABaseBoardIO10,
    NLABaseBoardIO11,
    NLABaseBoardIO12,
    NLABaseBoardWhiteLED,
    NLABaseBoardBlueLED
    
};

typedef NS_ENUM(NSInteger, NLAAxis) {
    NLAXaxis = 0,
    NLAYAxis,
    NLAZAxis

};


static const uint16_t maxAnalogInValue = 0x1FFF;



//typedef enum NLASolderBoardDigitalPort : uint16_t {
//    NLASolderBoardDigitalSB1 = 0x0020,
//    NLASolderBoardDigitalSB2 = 0x0040,
//    NLASolderBoardDigitalSB3 = 0x0080,
//    NLASolderBoardDigitalSB4 = 0x0010,
//} NLASolderBoardDigitalPort;
//
//typedef enum NLASolderBoardAnalogPort : uint8_t {
//    NLASolderBoardAnalogSB1 = 0x20,
//    NLASolderBoardAnalogSB2 = 0x40,
//    NLASolderBoardAnalogSB3 = 0x80,
//    NLASolderBoardAnalogSB4 = 0x10,
//} NLASolderBoardAnalogPort;

typedef signed char NLADigitalPortMode;
typedef signed char NLADigitalSignal;

static const NLADigitalSignal HIGH = 1;
static const NLADigitalSignal LOW = 0;
static const NLADigitalPortMode INPUT = 1;
static const NLADigitalPortMode OUTPUT = 0;

typedef void(^NLADigitalInputHandler)(NLADigitalReadData *readData, NSError *error);
typedef void(^NLAAnalogInputHandler)(NLABaseBoardIOPort changedPort, uint16_t analogValue, NSError *error);

// ----------------------------------------
// OAD
// ----------------------------------------


typedef void (^NLAOADUpdateStatusHandler)(NLAOADUpdateStatus *status, NSError *error);


@interface NLAConstants : NSObject

@end
