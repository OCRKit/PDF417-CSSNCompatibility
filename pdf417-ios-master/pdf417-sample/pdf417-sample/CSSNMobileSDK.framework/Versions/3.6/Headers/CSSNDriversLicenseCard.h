//
//  CSSNLicenseCard.h
//
//  Created by Diego Arena on 11/19/12.
//  Copyright (c) 2013 CodigoDelSur. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CSSNCardResult.h"

@interface CSSNDriversLicenseCard : CSSNCardResult

@property (nonatomic, strong) NSString  *dateOfBirth4;
@property (nonatomic, strong) NSString  *dateOfBirth;
@property (nonatomic, strong) NSString  *dateOfBirthLocal;
@property (nonatomic, strong) NSString  *idCountry;
@property (nonatomic, strong) NSString  *countryShort;
@property (nonatomic, strong) NSString  *county;
@property (nonatomic, strong) NSString  *expirationDate4;
@property (nonatomic, strong) NSString  *expirationDate;
@property (nonatomic, strong) NSString  *eyeColor;
@property (nonatomic, strong) NSData    *faceImage;
@property (nonatomic, strong) NSString  *hairColor;
@property (nonatomic, strong) NSString  *height;
@property (nonatomic, strong) NSString  *issueDate4;
@property (nonatomic, strong) NSString  *issueDate;
@property (nonatomic, strong) NSString  *issueDateLocal;
@property (nonatomic, strong) NSString  *licenceClass;
@property (nonatomic, strong) NSString  *licenceId;
@property (nonatomic, strong) NSString  *restriction;
@property (nonatomic, strong) NSString  *sex;
@property (nonatomic, strong) NSData    *signatureImage;
@property (nonatomic, strong) NSString  *state;
@property (nonatomic, strong) NSString  *weight;
@property (nonatomic, strong) NSString  *zip;
@property (nonatomic, strong) NSString  *city;
@property (nonatomic, strong) NSString  *address;
@property (nonatomic, strong) NSString  *address2;
@property (nonatomic, strong) NSString  *address3;
@property (nonatomic, strong) NSString  *address4;
@property (nonatomic, strong) NSString  *address5;
@property (nonatomic, strong) NSString  *address6;
@property (nonatomic, strong) NSString  *audit;
@property (nonatomic, strong) NSString  *CSC;
@property (nonatomic, strong) NSString  *docType;
@property (nonatomic, strong) NSString  *endorsements;
@property (nonatomic, strong) NSString  *fatherName;
@property (nonatomic, strong) NSString  *fee;
@property (nonatomic, strong) NSString  *isBarcodeRead;
@property (nonatomic, strong) NSString  *isIDVerified;
@property (nonatomic, strong) NSString  *isOcrRead;
@property (nonatomic, strong) NSString  *motherName;
@property (nonatomic, strong) NSString  *name;
@property (nonatomic, strong) NSString  *nameFirst;
@property (nonatomic, strong) NSString  *nameLast;
@property (nonatomic, strong) NSString  *nameLast1;
@property (nonatomic, strong) NSString  *nameLast2;
@property (nonatomic, strong) NSString  *nameMiddle;
@property (nonatomic, strong) NSString  *nameSuffix;
@property (nonatomic, strong) NSString  *nationality;
@property (nonatomic, strong) NSString  *original;
@property (nonatomic, strong) NSString  *placeOfBirth;
@property (nonatomic, strong) NSString  *placeOfIssue;
@property (nonatomic, strong) NSString  *results2D;
@property (nonatomic, strong) NSString  *sigNum;
@property (nonatomic, strong) NSString  *socialSecurity;
@property (nonatomic, strong) NSString  *text1;
@property (nonatomic, strong) NSString  *text2;
@property (nonatomic, strong) NSString  *text3;
@property (nonatomic, strong) NSString  *type;
@property (nonatomic, strong) NSString  *nameFirst_NonMRZ;
@property (nonatomic, strong) NSString  *nameLast_NonMRZ;
@property (nonatomic, strong) NSString  *nameMiddle_NonMRZ;
@property (nonatomic, strong) NSString  *nameSuffix_NonMRZ;
@property (nonatomic, strong) NSString  *IsAddressCorrected;
@property (nonatomic, strong) NSString  *IsAddressVerified;
@property (nonatomic, strong) NSNumber  *regionID;

@property (nonatomic, strong) NSString  *license;
@property (nonatomic, strong) NSData    *licenceImage;

-(id)initWithDictionary:(NSDictionary*)dictionary regionID:(int)regionID;
@end
