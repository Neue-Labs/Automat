//
//  NLABaseBoard.h
//  AutomatLibApp
//
//  Created by Emil Lundgren on 2015-08-10.
//  Copyright (c) 2015 Emil Lundgren. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NLAAutomatDevice.h"
#import "NLAClimateData.h"
#import "NLAMotionData.h"
#import "NLADigitalBlinkSequence.h"
#import "NLAI2CMutableWriteData.h"
#import "NLAI2CMutableReadData.h"

/**
 *  Handles a connected Automat Baseboard. This is where you access all the
 *  onboard functionality of a Baseboard.
 */

@interface NLABaseBoard : NLAAutomatDevice

/**
 *  Setting the climateReadoutRate will change the update rate of bluetooth
 *  readout rate for the humidity and temperature sensors. The value is set
 *  in seconds.
 */
@property (nonatomic, assign) uint16_t climateReadoutRate;
/**
 *  Setting this will update the output data rate of the accelerometer.
 *  Bluetooth will send the data at the same rate up to 208Hz. After that
 *  the value sent will be the average of the recent values on the device.
 *  E.g, if you set the accelerometer odr to NLAMotionHighPerformanceMode416Hz,
 *  the values will be the average ov two values, sent over bluetooth at 208Hz.
 *  If the accelerometer and gyroscope runs at different ODR values, the data will
 *  be sent at the highest rate of the two.
 */
@property (nonatomic, assign) NLAMotionSensorODRValue accelerometerODR;
/**
 * @see accelerometerODR.
 */
@property (nonatomic, assign) NLAMotionSensorODRValue gyroscopeODR;

/**
 *  When the climate sensors are active, this value can be read to retreive
 *  the latest temperature and humidity data received from the device.
 */
@property (nonatomic, strong, readonly) NLAClimateData *climateData;
/**
 * When the accelerometer or/and the gyroscope is active, the latest values
 * can be read here.
 */
@property (nonatomic, strong, readonly) NLAMotionData *motionData;



//***********************
//   CLIMATE SENSORS    *
//***********************

/**
 *  Activates the onboard temperature and humidity sensor.
 *  Values are sent from the Baseboard to the iOS device and can be 
 *  readout from the climateData property.
 *
 *  @param odr The readout rate for the temperature and humidity sensor in seconds.
 */
-(void) startClimateSensorWithReadoutRate:(uint16_t) odr;
/**
 *  This will start the climate sensors at their latest set update rate, or a 
 *  default update rate if none has been previously set. The handler block will
 *  receive callbacks with the latest NLAClimateData object containing the new 
 *  temperature and humidity values from the sensors.
 *
 *  @param handler A block for callback when the new data from the sensors are received.
 */
-(void) registerClimateSensorHandler:(NLASensorHandler) handler;
/**
 *  Removes the handler from the array of handlers. If no handlers are left,
 *  notifications from this sensor will be turned off until a handler is added.
 *
 *  @param handler The handler to remove
 */
-(void) removeClimateSensorHandler:(NLASensorHandler) handler;
/**
 *  Stop the readout of climate sensor data.
 */
-(void) stopClimateSensor;

//***********************
//    MOTION SENSORS    *
//***********************


@property (nonatomic) NLAGyroscopeRange gyroscopeRange;
@property (nonatomic) NLAAccelerometerRange accelerometerRange;


/**
 *  Set the mode of the accelerometer and gyroscope handler. Either listen to raw acc and 
 *  gyro values or use one of the motion features like tap or tilt detection.
 *  See NLAConstants.h and chech out the different available features.
 *
 *  @param handler The feature of choice
 */
-(void) enableMotionSensorFeature:(NLAMotionSensorFeature) feature;


/**
 *  Register a handler block to receive data when a motion sensor feature event has been
 *  detected.
 *
 *  @param handler A block for callback when an event is detected.
 */
-(void) registerMotionFeaturesHandler:(NLAMotionFeaturesHandler) handler;
/**
 *  Removes the handler from the array of handlers. If no handlers are left,
 *  notifications from this sensor will be turned off until a handler is added.
 *
 *  @param handler The handler to remove
 */
-(void) removeMotionFeaturesHandler:(NLAMotionFeaturesHandler) handler;

/**
 *  Start the gyroscope of the Baseboard at the given output data rate.
 *  Values can be read out from the motionData property
 *  If you're interested in orientation data, @see startMotionSensorsWithODR:
 *
 *  @param odr An NLAMotionSensorODRValue
 *  @see accelerometerODR
 */


-(void) startGyroscopeSensorWithReadoutRate:(NLAMotionSensorODRValue) odr;

/**
 *  @see startGyroscopeSensorWithReadoutRate:
 *
 *  @param odr
 */
-(void) startAccelerometerWithReadoutRate:(NLAMotionSensorODRValue) odr;
/**
 *  Starts the gyroscope and the accelerometer at the giver ODR value.
 *  In order to receive correct orientation data, this method needs to be invoked.
 *
 *  @param odr output data rate
 *  @see startGyroscopeSensorWithReadoutRate:
 */
-(void) startMotionSensorsWithODR:(NLAMotionSensorODRValue) odr;
/**
 *  Will start both the accelerometer and the gyroscope of the Baseboard
 *  at the latest set odr value. If it hasn't been set previously, a default
 *  value will be used.
 *
 *  @param handler A block that will receive callbacks with NLAMotionData when
 *  new data has come in from the Baseboard.
 */
-(void) registerMotionSensorHandler:(NLASensorHandler) handler;
/**
 *  Removes the handler from the array of handlers. If no handlers are left,
 *  notifications from this sensor will be turned off until a handler is added.
 *
 *  @param handler The handler to remove
 */
-(void) removeMotionSensorHandler:(NLASensorHandler) handler;
/**
 *  Set the odr value simultaneously for the acceleromter and gyroscope.
 *
 *  @param odrValue
 *  @see accelerometerODR
 */
-(void) setMotionSensorsODR:(NLAMotionSensorODRValue) odrValue;
/**
 *  In order to calibrate the gyroscope, put the Baseboard flat and completely still
 *  on a table and call this method. The handler block passed in will be invoked when
 *  the process is finished.
 *
 *  @param handler A block that will receive callback when the calibration process is finished.
 */
-(void) calibrateGyroscope:(NLAGyroscopeCalibrationHandler) handler;
@property (nonatomic, readonly) BOOL gyroIsCalibrated;


/**
 *  This sets the cutoff for the lowpass filter applied to the outgoing
 *  euler angles rotation values to smoothen them. Default is 1/100Hz.
 *
 *  @param cutoffValue 
 */
-(void) setOrientationOutputFilterCutoff:(double) cutoffValue;


/**
 *  Since the version of the Baseboard this NLABaseBoard class is set to handle
 *  lacks a magnetometer, the yaw axis will drift. Therefore, a reset might be 
 *  necessary from time to time.
 */
-(void) resetMotionAlgorithms;

/**
 *  Locks the yaw axis when calculating the orientation.
 *  Default is NO.
 */
-(void) enableMotionYawLock:(BOOL) enabled;

/**
 * Set which axes to return the angular relationship between. Default body and
 * intertial is the z axis.
 * This is an automotion feature and requires that the gyroscope is calibrated. 
 * @see calibrateGyroscope:.
 * The output is available in the NLAMotionDataObject provided by the handler.
 */
-(void) angularRelationshipBodyAxis:(NLAAxis) bodyAxis intertialAxis:(NLAAxis) intertialAxis;


//*************************
// PORT I/O CONFIGURATION *
//*************************

/**
 *  This sets the mode INPUT or OUTPUT for a digital port to be written to the Baseboard.
 *  To actually set it on the Baseboard @see writeDigitalPortModes.
 *  Note that for NLABaseBoardBlueLED and NLABaseBoardWhiteLED only OUTPUT mode is possible.
 *
 *  @param portMode INPUT or OUTPUT
 *  @param port     An NLABaseBoardDigitalPort
 */
-(void) setDigitalPortMode:(NLADigitalPortMode) portMode forDigitalPort:(NLABaseBoardIOPort) port;
/**
 *  See what mode a port is set to. It returns the value set by @see setDigitalPortMode:forDigitalPort:
 *  regardless of weither it has been written to the Baseboard or not.
 *
 *  @param port The desired port.
 *
 *  @return The mode which is INPUT or OUTPUT.
 */
-(NLADigitalPortMode) digitalPortModeForPort:(NLABaseBoardIOPort) port;
/**
 *  Set the signal HIGH or LOW to be written for a port to the Baseboard.
 *  To set the actual value on the Baseboard, you need to write it using
 *  @see writeDigitalPortSignalStates
 *
 *  @param signal HIGH or LOW
 *  @param port   The port to set the signal on.
 */
-(void) setDigitalSignal:(NLADigitalSignal) signal forDigitalPort:(NLABaseBoardIOPort) port;
/**
 *  Returns the digital signal for a port as set by @see setDigitalSignal:forDigitalPort:
 *  This is the value set on the software side, regardless of weither it has been written 
 *  to the baseboard or not.
 *
 *  @param port The port
 *
 *  @return The signal state, HIGH or LOW.
 */
-(NLADigitalSignal) digitalSignalForPort:(NLABaseBoardIOPort) port;
/**
 *  When registering a digital input handler, @see registerDigitalInputHandler:
 *  the behaviour of the incoming values will be different depending on this setting.
 *  Inverting the digital bit for a port can have the effect that when a digital in signal
 *  is detected, you will read the value of that port on the incoming signal. Otherwise,
 *  the behaviour is opposite. You will get the value of the given port when the signal
 *  is back in its previous state.
 *
 *  @param isInverted
 *  @param port
 */
-(void) invertDigitalInBit:(BOOL)isInverted forPort:(NLABaseBoardIOPort) port;
/**
 *  Enables one of the analog ports of the Baseboard for reading analog in values.
 *  There are 8 analog ports on the BaseBoard, thus NLABaseBoardIO1 - NLABaseBoardIO8
 *  can be used for analog in.
 *
 *
 *  @param analogPort
 */
-(void) enableAnalogPort:(NLABaseBoardIOPort) analogPort;
-(void) disableAnalogPort:(NLABaseBoardIOPort) analogPort;
-(BOOL) isAnalogPortEnabled:(NLABaseBoardIOPort) analogPort;
/**
 *  This sets the sensitivity for all analog ports. The default value is 0x00, and if
 *  registering an analog input handler @see registerAnalogInputHandler: you will receive
 *  callbacks constantly. Recommended setting is 0x02. To write the setting to the board,
 *  @see writeAnalogSettings
 *
 *  @param inSensitivity An 8 bit value setting the analog in sensitivity.
 */
-(void) setAnalogInSensitivity:(uint8_t) inSensitivity;

//*************************
//        PORT I/O        *
//*************************

/**
 *  Write the digital port signal states to the Baseboard as set by
 *  @see setDigitalPortMode:forPort:. The idea is that you can set several
 *  the values for several ports on the software side and write the actual
 *  setting to the Baseboard in one write.
 */
-(void) writeDigitalPortSignalStates;
/**
 *  Write the digital port modes to the Baseboard as set by
 *  @see setDigitalSignal:forPort:
 *  @see writeDigitalPortSignalStates
 */
-(void) writeDigitalPortModes;
/**
 *  Writes the enabled analog ports, @see enableAnalogPort: and the
 *  analog in sensitivity @see setAnalogInSensitivity to the Baseboard.
 */
-(void) writeAnalogSettings;
/**
 *  Write the inverted bits data to the Baseboard as set by
 *  @see invertDigitalInBit:forPort:
 *  @see writeDigitalPortSignalStates
 */
-(void) writeInvertedBits;
/**
 *  Register a handler to receive callback on digital in changes.
 *  First you need to set a port to input mode, @see setDigitalPortMode:forPort:
 *  Then you write the changes to the board, @see writeDigitalPortModes
 *
 *  @param handler A handler block that will be invoked when receivning digital in
 *  notifications from the Baseboard.
 */
-(void) registerDigitalInputHandler:(NLADigitalInputHandler) handler;
/**
 *  Removes the handler from the array of handlers. If no handlers are left,
 *  notifications from this sensor will be turned off until a handler is added.
 *
 *  @param handler The handler to remove
 */
-(void) removeDigitalInputHandler:(NLADigitalInputHandler) handler;
/**
 *  Register a handler to receive callback when changes are detected on
 *  an analog port. First you need to enable the analog port you wish
 *  to use @see enableAnalogPort. You probably also need to set the analog
 *  in sensitivity @see setAnalogInSensitivity.
 *  Also make sure to write the changes @see writeAnalogSettings.
 *
 *  @param handler A handler block that is invoked when analog in values are changed.
 */
-(void) registerAnalogInputHandler:(NLAAnalogInputHandler) handler;
/**
 *  Removes the handler from the array of handlers. If no handlers are left,
 *  notifications from this sensor will be turned off until a handler is added.
 *
 *  @param handler The handler to remove
 */
-(void) removeAnalogInputHandler:(NLAAnalogInputHandler) handler;
/**
 *  You can create an NLADigitalBlinkSequence object to write a blink sequence
 *  to one or more digital ports on the Baseboard. When invoking this method, it
 *  will write the sequence to the Baseboard.
 *  First you might have to set the port mode(s) to OUTPUT using 
 *  @see setDigitalPortMode:forPort: and write the changes to the Baseboard using
 *  @see writeDigitalPortModes.
 *
 *  @param blinkSequence An object containing data about the blink sequence.
 */
-(void) writeDigitalBlinkSequence:(NLADigitalBlinkSequence *) blinkSequence;

//***********************
//          I2C         *
//***********************

/**
 *  Writes i2c commands to the Baseboard or an external device connected to the Baseboard.
 *  When the write has been performed, CoreBluetooth makes a callback which will invoke the
 *  passed in handler block. This is a receipt that the write was performed on the software side.
 *  The handler block will be passed the data that was sent to write the command.
 *
 *  @param i2cData An object containing info about i2c address and commands.
 *  @param handler A block that will be invoked when the bluetooth write has been performed.
 */
-(void) writeI2CCommand:(NLAI2CMutableWriteData *) i2cData withHandler:(NLAI2CWriteHandler) handler;
/**
 *  Writes a read command to the Baseboard or an external device connected to the Baseboard.
 *  The difference between a read and a write command is that when performing a read command you 
 *  expect a response from the device you wrote to.
 *  To test this you can write a read command to one of the registers on the accelerometer of the Baseboard.
 *  The register is called - who am I - the address is 6A and the command is 0F. The response
 *  length is 1, for 1 byte. It will respond with the hex value 0x69.
 *
 *  @param i2cData An object containing info about i2c address, commands and expected response length.
 *  @param handler A block that will be invoked when the device responded with an NLAReadResponseData object.
 *
 */
-(void) readI2CCommand:(NLAI2CMutableReadData *) i2cData withHandler:(NLAI2CReadHandler) handler;




@end
