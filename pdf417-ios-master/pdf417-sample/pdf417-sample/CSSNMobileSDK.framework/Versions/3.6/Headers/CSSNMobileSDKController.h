//
//  CSSNCardCaptureController
//  CSSNCardCapture Framework for iOS
//
//  Created by CSSN on 11/19/12.
//  Copyright (c) 2013 CSSN. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "CSSNPopoverController.h"
#import "CSSNCardProcessRequestOptions.h"
#import "CSSNError.h"
#import "CSSNCardResult.h"
#import "CSSNMedicalInsuranceCard.h"
#import "CSSNDriversLicenseCard.h"
#import "CSSNDriverLicenseDuplexCard.h"
#import "CSSNPassaportCard.h"
#import "CSSNCardType.h"


@protocol CSSNMobileSDKControllerCapturingDelegate <NSObject>

@required

/**
 Called to inform the delegate that a card image was captured
 @param cardImage the card image
 */
- (void)didCaptureImage:(UIImage*)cardImage;

/**
 Called to inform the delegate that a barcode image was captured
 @param data the barcode string
 */
- (void)didCaptureData:(NSString*)data;

/**
 Called to inform the delegate that the user pressed the back button
 */
- (void)didPressBackButton;

/**
 Called to inform delegate that the request failed.
 @param error the reason why the request failed
 @discussion the delegate is in charge of analysing the error sent and inform the user.
 */
- (void)didFailWithError:(CSSNError*)error;

@optional

/**
 Called to inform the delegate that the framework was validated
 */
- (void)mobileSDKWasValidated:(BOOL)wasValidated;

/**
 Called to inform the delegate that the capture interface did appear
 */
- (void)cardCaptureInterfaceDidAppear;

/**
 Called to inform the delegate that the capture interface did disappear
 */
- (void)cardCaptureInterfaceDidDisappear;

/**
 Called to obtain the back button image displayed in the card capture interface
 @return the back button image
 @discussion if this method is not implemented or nil is returned, we'll display a white rounded button with "back" text
 @discussion this delegate method is only called when presenting the card capture interface full screen. If card capture interface is presented in a UIPopOverController, this method is not called at all because a Cancel UIBarButtonItem in the UINavigationBar is used instead.
 */
- (UIImage*)imageForBackButton;

/**
 Called to obtain the back button position in the screen.
 @return the point where the back button should be positioned
 @discussion in case this method is not implemented by the delegate, we'll set a default location for the button though we encourage you to set the position manually.
 @discussion if your application supports multiple screen sizes then you are in charge of returning the correct position for each screen size.
 @discussion this delegate method is only called when presenting the card capture interface full screen. If card capture interface is presented in a UIPopOverController, this method is noot called at all because a Cancel UIBarButtonItem in the UINavigationBar is used instead.
 */
- (CGRect)frameForBackButton;

/**
 Called to show or not show the back button in the card capture interface
 @return show or not show the back button
 @discussion if this method is not implemented or nil is returned, we'll display a the button with "back" text
 @discussion this delegate method is only called when presenting the card capture interface full screen. If card capture interface is presented in a UIPopOverController, this method is not called at all because a Cancel UIBarButtonItem in the UINavigationBar is used instead.
 */
- (BOOL)showBackButton;

/**
 Called to obtain the help image displayed in the card capture interface
 @return the help image
 @discussion if this method is not implemented or nil is returned, we'll not display a help image view
 */
- (UIImage*)imageForHelpImageView;

/**
 Called to obtain the help image position in the screen.
 @return the point where the help image should be positioned
 @discussion in case this method is not implemented by the delegate, we'll set a default location for the help image though we encourage you to set the position manually.
 @discussion if your application supports multiple screen sizes then you are in charge of returning the correct position for each screen size.
 */
- (CGRect)frameForHelpImageView;

/**
 Called to obtain the watermark Message displayed in the card capture interface
 @return the watermark Message
 @discussion if this method is not implemented or nil is returned, we'll not display a watermark Message view
 */
- (NSString*)stringForWatermarkLabel;

/**
 Called to obtain the watermark label position in the screen.
 @return the point where the watermark label should be positioned
 @discussion in case this method is not implemented by the delegate, we'll set a default location for the help image though we encourage you to set the position manually.
 @discussion if your application supports multiple screen sizes then you are in charge of returning the correct position for each screen size.
 */
- (CGRect)frameForWatermarkView;

@end

@protocol CSSNMobileSDKControllerProcessingDelegate <NSObject>

@required

/**
 Called to inform delegate that the request completed succesfully.
 @param result the data parsed from the card image
 */
- (void)didFinishProcessingCardWithResult:(CSSNCardResult*)result;

/**
 Called to inform delegate that the request failed.
 @param error the reason why the request failed
 @discussion the delegate is in charge of analysing the error sent and inform the user.
 */
- (void)didFailWithError:(CSSNError*)error;

@optional

/**
 Called to inform the delegate that the framework was validated
 */
- (void)mobileSDKWasValidated:(BOOL)wasValidated;

@end

@interface CSSNMobileSDKController : NSObject{}

@property (weak, nonatomic) id<CSSNMobileSDKControllerCapturingDelegate, CSSNMobileSDKControllerProcessingDelegate> mobileSDKDelegate;
/**
 Use this method to obtain an instance of the CSSNMobileSDKController if Username and password is correct
 @param key your License Key
 @param delegate your delegate
 @param cloudAddress your cloud Address
 @discussion never try to alloc/init this class, always obtain an instance through this method.
 @return the CSSNMobileSDKController instance
 */
+ (CSSNMobileSDKController*)initCSSNMobileSDKWithLicenseKey:(NSString*)key delegate:(id<CSSNMobileSDKControllerCapturingDelegate, CSSNMobileSDKControllerProcessingDelegate>)delegate andCloudAddress:(NSString*)cloudAddress;

/**
 Use this method to obtain an instance of the CSSNMobileSDKController if License key is correct
 @param key your License Key
 @param delegate your delegate
 @discussion never try to alloc/init this class, always obtain an instance through this method.
 @return the CSSNMobileSDKController instance
 */
+ (CSSNMobileSDKController*)initCSSNMobileSDKWithLicenseKey:(NSString*)key andDelegate:(id<CSSNMobileSDKControllerCapturingDelegate, CSSNMobileSDKControllerProcessingDelegate>)delegate;

/**
 Use this method to obtain an instance of the CSSNMobileSDKController if License key was set
 @discussion never try to alloc/init this class, always obtain an instance through this method.
 @return the CSSNMobileSDKController instance
 */
+ (CSSNMobileSDKController*)initCSSNMobileSDK;


/**
 Use this method to present the card capture interface.
 @param viewController the UIViewController object from which we'll present the card capture interface
 @param delegate the delegate of the card capture interface
 @param typeCard the type of the card capture interface
 @discussion a valid viewController is required
 */

- (void)showCardCaptureInterfaceInViewController:(UIViewController*)vc delegate:(id<CSSNMobileSDKControllerCapturingDelegate>)delegate andTypeCard:(CSSNCardType)typeCard __deprecated;

/**
 Use this method to get an UIPopOverController containing the card capture interface
 @param delegate the delegate of the card capture interface
 @param viewController the UIViewController object from which we'll present the card capture interface
 @param typeCard the type of the card capture interface
 @return UIPopOverController with camera view.
 @discussion a valid viewController is required
 @discussion content size of this UIPopOverController cannot be changed.
 */
- (CSSNPopoverController*)cardCapturePopOverControllerWithViewController:(UIViewController*)vc delegate:(id<CSSNMobileSDKControllerCapturingDelegate>)delegate andTypeCard:(CSSNCardType)typeCard;

/**
 Use this method to present the card capture interface.
 @param viewController the UIViewController object from which we'll present the card capture interface
 @param delegate the delegate of the card capture interface
 @param typeCard the type of the card capture interface
 @discussion a valid viewController is required
 */
- (void)showManualCardCaptureInterfaceInViewController:(UIViewController*)viewController delegate:(id<CSSNMobileSDKControllerCapturingDelegate>)delegate andTypeCard:(CSSNCardType)typeCard __deprecated;

/**
 Use this method to present the barcode capture interface.
 @param viewController the UIViewController object from which we'll present the card capture interface
 @param delegate the delegate of the card capture interface
 @discussion a valid viewController is required
 */
- (void)showBarcodeCaptureInterfaceInViewController:(UIViewController*)viewController delegate:(id<CSSNMobileSDKControllerCapturingDelegate>)delegate __deprecated;

/**
Use this method to present the card capture interface.
@param viewController the UIViewController object from which we'll present the card capture interface
@param delegate the delegate of the card capture interface
@param typeCard the type of the card capture interface
@discussion a valid viewController is required
*/
- (void)showCameraInterfaceInViewController:(UIViewController*)vc delegate:(id<CSSNMobileSDKControllerCapturingDelegate>)delegate cardType:(CSSNCardType)cardType andFrontSide:(BOOL)isFrontSide;

/**
 Use this method to dismiss the card capture interface
 @discussion You cannot use [UIPopOverController dismissPopoverAnimated:] method to dismiss the UIPopOverController
 */
- (void)dismissCardCaptureInterface;

/**
 Use this method to start the camera
 @discussion you don't need to call this method after presenting the camera interface
 @discussion if we're already capturing video this method does nothing
 */
- (void)startCamera;

/**
 Use this method to stop the camera
 @discussion if camera is already stop, this method does nothing
 */
- (void)stopCamera;

/**
 Use this method to configure the License key
 @param key your LicenseKey
 @discussion you are in charge of setting License key on each application launch as part of the setup of the framework
 */
- (void)setLicenseKey:(NSString *)key;

/**
 Use this method to configure the Cloud Address of the server
 @param setCloudAddress the Cloud Address string including protocol, for example: https://myserver.com/
 */
- (void)setCloudAddress:(NSString *)serverBaseURL;

/**
 Use this method to activate the license key
 @param key the license key 
 */
- (void)activateLicenseKey:(NSString*)key;

/**
 Use this method to set the height of the cropped image
 @param height the height of the cropped card
 @discussion you need to set the width with setWidth:(int)width to crop the image with these values
 */
-(void)setHeight:(int)height;

/**
 Use this method to set the width of the cropped image
 @param width the width of the cropped card
 @discussion you need to set the height with setHeight:(int)height to crop the image with these values
*/
-(void)setWidth:(int)width;

/**
 Use this method to set the orientation of camera detect.
 @param isLandscape the boolean with orientation
 */
-(void)setCameraLandscape:(BOOL)isLandscape;


/**
 Called to set a customize appear message, background color, time lenght and frame.
 @discussion in case this method in not implementd by the delegate, we'll set a default message, background color, time lenght and frame.
 */
-(void)setInitialMessage:(NSString*)message frame:(CGRect)frame backgroundColor:(UIColor*)backgroundColor duration:(int)timeLenght;

/**
 Called to set a customize finaly message, background color, time lenght and frame.
 @discussion in case this method in not implementd by the delegate, we'll set a default message, background color, time lenght and frame.
 */
-(void)setCapturingMessage:(NSString*)message frame:(CGRect)frame backgroundColor:(UIColor*)backgroundColor duration:(int)timeLenght;

    
/**
 Use this method to process a card.
 @param frontImage the front image of the card.
 @param backImage the back image of the card.
 @param stringData the string data of the back side of the card.
 @param delegate the delegate of the process request
 @param options the options of the process request.
 @discussion you must always provide a front image, back image is optional
 @discussion use the options object to indicate the type of card you're trying to process (i.e. License, Medical). Processing will fail if you don't provide this parameter.
 @discussion you're encourage to provide a delegate to be informed about what happened with your processing request. You can change the delegate using the cardProcessingDelegate property of this class.
 @discussion you should call this method only once and wait until your delegate is informed. If you call this method while we're already processing a card, we'll ignore your second call.
 @discussion The recommended size to this images is 1009 width and relative height to the width.
 */
- (void)processFrontCardImage:(UIImage*)frontImage
                BackCardImage:(UIImage*)backImage
                andStringData:(NSString*)stringData
                 withDelegate:(id<CSSNMobileSDKControllerProcessingDelegate>)delegate
                  withOptions:(CSSNCardProcessRequestOptions*)options;

@end
