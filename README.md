# AUTOMAT iOS API by Neue labs

Neue labs presents AUTOMAT, a small and flexible platform for building personal IoT. AUTOMAT is built to boost creativity and create real products for professional creatives in agencies, studios, innovation & R&D departments. Use the same hardware and software in both prototyping and industrialisation to cut costs dramatically and shorten time to market. Neue labs AUTOMAT quite simply makes great ideas happen.

Use this API to develop your own iOS apps connecting via BlueTooth to AUTOMAT hardware.

## Requirements

* [AUTOMAT hardware](http://automat.space) 
* [Apple developer account](http://developer.apple.com)
* iOS device running iOS 8.0 or higher

## Installation

Simply copy the NeueLabsAutomat.framework to your project.

## Simple test

Import the framework header file with:
```ocj-c
#import <NeueLabsAutomat/NeueLabsAutomat.h>
```

Start scanning for AUTOMAT hardware:
```ocj-c
NLAConnectionManager *connectionManager = [NLAConnectionManager sharedConnectionManager];
[connectionManager startScanningForAutomatDevices];
```

When a device is discovered a notification will be posted using NSNotificationCenter.
To detect this, you need to register for notifications as shown below. The notification being sent will provide
a unique identifier to the located AUTOMAT device. Use this identifier to connect to the device. 
```ocj-c

// Register for notifications
[[NSNotificationCenter defaultCenter] addObserverForName:kAutomatDeviceWasDiscoveredNotification
                                                      object:nil queue:[NSOperationQueue mainQueue]
                                                  usingBlock:^(NSNotification *note){
                                                    
    // Connect to device
    [[NLAConnectionManager sharedConnectionManager] 
    connectToDeviceWithIdentifier:[note.userInfo objectForKey:kAutomatDeviceIdentifier]];
                                                          
    }];
```

Finally, when a device is connected, another notification is being sent. You can now retreive an instance of
the NLAAutomatDevice subclass handling the connected device as shown below. From here you can access all of the device's built-in functionality. The below example shows blinking the built in LED:s on a Baseboard.
```ocj-c
[[NSNotificationCenter defaultCenter] addObserverForName:kAutomatDeviceDidConnectNotification
                                                      object:nil queue:[NSOperationQueue mainQueue]
                                                  usingBlock:^(NSNotification *note){
                                                     
    NSLog(@"Did connect Automat device!");
                                                      
    // Through the NLABaseboard object you access all the functionality
    // of the connected baseboard.
    NLABaseBoard *baseboard = (NLABaseBoard *) [connectionManager automatDeviceWithIdentifier:[note.userInfo     objectForKey:kAutomatDeviceIdentifier]];
                                                      
    NLADigitalBlinkSequence *blinkSequence = [[NLADigitalBlinkSequence alloc] init];
    blinkSequence.nrOfBlinks = 10;
    blinkSequence.outputPeriod = 100; // ms
    blinkSequence.outputRatio = 50; // %
    [blinkSequence addDigitalPort:NLABaseBoardWhiteLED];
    [blinkSequence addDigitalPort:NLABaseBoardBlueLED];
   
    [baseboard writeDigitalBlinkSequence:blinkSequence];

}];
```


