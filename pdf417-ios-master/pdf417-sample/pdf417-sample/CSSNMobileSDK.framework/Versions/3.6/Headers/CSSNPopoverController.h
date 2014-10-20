//
//  CSSNPopoverController.h
//  ISGCardCaptureFramework-iOS
//
//  Created by Diego Arena on 6/28/13.
//  Copyright (c) 2013 DB-Interactive. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CSSNCardType.h"

@interface CSSNPopoverController : UIPopoverController
-(id)initWithCardType:(CSSNCardType)cardType andDelegate:(id)delegate isCameraLandscape:(BOOL)isLandscape;
-(void)setParentViewController:(UIViewController*)viewController;
-(void)orientationChanged;
@end
