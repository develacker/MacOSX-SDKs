//
//  MKOverlayPathRenderer.h
//  MapKit
//
//  Copyright (c) 2013, Apple Inc. All rights reserved.
//

#import <MapKit/MKFoundation.h>
#import <MapKit/MKOverlayRenderer.h>
#if TARGET_OS_IPHONE
#import <UIKit/UIKit.h>
#else
#import <AppKit/AppKit.h>
#endif

MK_CLASS_AVAILABLE(10_9, 7_0)
@interface MKOverlayPathRenderer : MKOverlayRenderer

#if TARGET_OS_IPHONE
@property (retain) UIColor *fillColor;
@property (retain) UIColor *strokeColor;
#else
@property (retain) NSColor *fillColor;
@property (retain) NSColor *strokeColor;
#endif

@property CGFloat lineWidth; // defaults to 0, which is MKRoadWidthAtZoomScale(currentZoomScale)
@property CGLineJoin lineJoin; // defaults to kCGLineJoinRound
@property CGLineCap lineCap; // defaults to kCGLineCapRound
@property CGFloat miterLimit; // defaults to 10
@property CGFloat lineDashPhase; // defaults to 0
@property (copy) NSArray *lineDashPattern; // an array of NSNumbers, defaults to nil

// subclassers should override this to create a path and then set it on
// themselves with self.path = newPath;
- (void)createPath;
// returns cached path or calls createPath if path has not yet been created
@property CGPathRef path; // path will be retained
- (void)invalidatePath;

// subclassers may override these
- (void)applyStrokePropertiesToContext:(CGContextRef)context
                           atZoomScale:(MKZoomScale)zoomScale;
- (void)applyFillPropertiesToContext:(CGContextRef)context
                         atZoomScale:(MKZoomScale)zoomScale;
- (void)strokePath:(CGPathRef)path inContext:(CGContextRef)context;
- (void)fillPath:(CGPathRef)path inContext:(CGContextRef)context;

@end
