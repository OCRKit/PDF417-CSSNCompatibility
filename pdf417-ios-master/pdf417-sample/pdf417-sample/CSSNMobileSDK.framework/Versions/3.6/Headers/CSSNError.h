//
//  CSSNProcessingError.h
//  CSSNMobileSDK
//
//  Created by Diego Arena on 9/6/13.
//  Copyright (c) 2013 DB-Interactive. All rights reserved.
//

#import <Foundation/Foundation.h>
typedef enum {
	CSSNErrorCouldNotReachServer = 0, //check internet connection
	CSSNErrorUnableToAuthenticate = 1, //keyLicense are incorrect
	CSSNErrorUnableToProcess = 2, //image received by the server was unreadable, take a new one
	CSSNErrorInternalServerError = 3, //there was an error in our server, try again later
	CSSNErrorUnknown = 4, //there was an error but we were unable to determine the reason, try again later
    CSSNErrorTimedOut = 5, //request timed out, may be because internet connection is too slow
    CSSNErrorAutoDetectState = 6, //Error when try to detect the state
    CSSNErrorWebResponse = 7, //the json was received by the server contain error
    CSSNErrorUnableToCrop = 8, //the received image can't be cropped.
    CSSNErrorInvalidLicenseKey = 9, //Is an invalid license key.
    CSSNErrorInactiveLicenseKey = 10, //Is an inative license key.
    CSSNErrorAccountDisabled = 11, //Is an account disabled.
    CSSNErrorOnActiveLicenseKey = 12, //there was an error on activation key.
    CSSNErrorValidatingLicensekey = 13 //The validation is still in process.
    
} CSSNErrorType;

@interface CSSNError : NSObject
@property (nonatomic) CSSNErrorType errorType;
@property (nonatomic, strong) NSString *errorMessage;

+ (CSSNError*)instanceWithError:(CSSNErrorType)errorType andMessage:(NSString*)errorMessage;
@end
