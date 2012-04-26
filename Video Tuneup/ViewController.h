//
//  ViewController.h
//  Video Tuneup
//
//  Created by Brian Jordan on 3/27/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import <AssetsLibrary/AssetsLibrary.h>
#import "SimpleEditor.h"
#import <MediaPlayer/MediaPlayer.h>

@class PlayerView;

// UIImagePickerControllerDelegate requires that we conform to UINavigationControllerDelegate
@interface ViewController : UIViewController <UINavigationControllerDelegate, UIImagePickerControllerDelegate> {
    AVURLAsset *asset;
    AVURLAsset *songAsset;
    
    // Related to scrubbing
    float mRestoreAfterScrubbingRate;
    BOOL seekToZeroBeforePlay;
    id mTimeObserver;
}

@property (nonatomic, retain) AVPlayer *player;
@property (nonatomic, retain) SimpleEditor *editor;
@property (retain) AVPlayerItem *playerItem;
@property (nonatomic, retain) IBOutlet PlayerView *playerView;
@property (nonatomic, retain) IBOutlet UIButton *playButton;
@property (nonatomic, retain) IBOutlet UIButton *pauseButton;
@property (nonatomic, retain) IBOutlet UIButton *rewindButton;
@property (nonatomic, retain) IBOutlet UIToolbar *videoNavBar;
@property (nonatomic, retain) IBOutlet UILabel *exportStatus;
@property (nonatomic, retain) IBOutlet UISlider* mScrubber;

@property (nonatomic, retain) IBOutlet UIButton *mediaLibraryButton;
@property (nonatomic, retain) UIPopoverController *mediaLibraryPopover;


- (void)hideCameraRollText;
- (IBAction)loadAssetFromFile:sender;
- (IBAction)loadAudioFromFile:sender;
- (IBAction)play:sender;
- (IBAction)pause:sender;
- (IBAction)rewind:sender;
- (IBAction)exportToCameraRoll:sender;
- (void)syncUI;
- (void)syncScrubber;
- (void)beginScrubbing:(id)sender;
- (void)scrub:(id)sender;
- (void)endScrubbing:(id)sender;
- (BOOL)isScrubbing;
- (void)initScrubberTimer;
- (CMTime)playerItemDuration;

- (void)exportDidFinish:(AVAssetExportSession*)session;

- (IBAction)showMediaLibrary:(id)sender;
@end