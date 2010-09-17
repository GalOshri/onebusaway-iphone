/**
 * Copyright (C) 2009 bdferris <bdferris@onebusaway.org>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#import "OBAApplicationContext.h"
#import "OBANavigationTargetAware.h"
#import "OBAArrivalsAndDeparturesForStopV2.h"
#import "OBABookmarkV2.h"
#import "OBAProgressIndicatorView.h"


@interface OBAStopViewController : UITableViewController <OBANavigationTargetAware,UIActionSheetDelegate,OBAModelServiceDelegate> {

	OBAApplicationContext * _appContext;
	NSString * _stopId;
	NSUInteger _minutesAfter;

	id<OBAModelServiceRequest> _request;
	NSTimer * _timer;
	
	OBAArrivalsAndDeparturesForStopV2 * _result;
	
	NSMutableArray * _allArrivals;
	NSMutableArray * _filteredArrivals;
	BOOL _showFilteredArrivals;
	
	NSDateFormatter * _timeFormatter;
	
	OBAProgressIndicatorView * _progressView;
}

- (id) initWithApplicationContext:(OBAApplicationContext*)appContext;
- (id) initWithApplicationContext:(OBAApplicationContext*)appContext stopId:(NSString*)stopId;
- (id) initWithApplicationContext:(OBAApplicationContext*)appContext stopIds:(NSArray*)stopIds;

@property (nonatomic,retain) NSString * stopId;
@property (nonatomic,retain) id<OBAModelServiceRequest> request;
@property (nonatomic,retain) OBAArrivalsAndDeparturesForStopV2 * result;

@end
