//
//  CSSNBarCodePDF417Card.h
//  sampleDebug
//
//  Created by Diego Arena on 5/6/14.
//  Copyright (c) 2014 cssn. All rights reserved.
//
#import "CSSNCardResult.h"
#import <Foundation/Foundation.h>

@interface CSSNDriverLicenseDuplexCard : CSSNCardResult

@property (nonatomic, strong) NSString  *dateOfBirth4;
@property (nonatomic, strong) NSString  *expirationDate4;
@property (nonatomic, strong) NSString  *eyeColor;
@property (nonatomic, strong) NSData    *faceImage;
@property (nonatomic, strong) NSString  *hairColor;
@property (nonatomic, strong) NSString  *height;
@property (nonatomic, strong) NSString  *issueDate4;
@property (nonatomic, strong) NSString  *licenceClass;
@property (nonatomic, strong) NSString  *sex;
@property (nonatomic, strong) NSData    *signatureImage;
@property (nonatomic, strong) NSString  *state;
@property (nonatomic, strong) NSString  *weight;
@property (nonatomic, strong) NSString  *zip;
@property (nonatomic, strong) NSString  *city;
@property (nonatomic, strong) NSString  *address;
@property (nonatomic, strong) NSString  *isAddressCorrected;
@property (nonatomic, strong) NSString  *isAddressVerified;
@property (nonatomic, strong) NSString  *isBarcodeRead;
@property (nonatomic, strong) NSString  *isIDVerified;
@property (nonatomic, strong) NSString  *isOcrRead;
@property (nonatomic, strong) NSString  *name;
@property (nonatomic, strong) NSString  *nameFirst;
@property (nonatomic, strong) NSString  *nameLast;
@property (nonatomic, strong) NSString  *nameMiddle;
@property (nonatomic, strong) NSString  *nameSuffix;
@property (nonatomic, strong) NSString  *results2D;
@property (nonatomic, strong) NSString  *idCountry;
@property (nonatomic, strong) NSNumber  *regionID;

@property (nonatomic, strong) NSString  *license;
@property (nonatomic, strong) NSData    *licenceImage;

-(id)initWithDictionary:(NSDictionary*)dictionary regionID:(int)regionID;
@end
