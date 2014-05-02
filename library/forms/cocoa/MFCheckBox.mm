/* 
 * Copyright (c) 2009, 2013, Oracle and/or its affiliates. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; version 2 of the
 * License.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301  USA
 */

#import "MFCheckBox.h"

#import "MFView.h"
#import "MFMForms.h"

@implementation MFCheckBoxImpl


- (id)initWithObject:(::mforms::CheckBox*)aCheckBox square:(BOOL)square
{
  self= [super initWithObject:aCheckBox buttonType: ::mforms::PushButton];
  if (self)
  {
    [self setButtonType: square ? NSPushOnPushOffButton : NSSwitchButton];
    if (square)
      [self setBezelStyle: NSShadowlessSquareBezelStyle];
    else
      [self setBezelStyle: NSRegularSquareBezelStyle];

    mTopLeftOffset= NSMakePoint(0, 0);
    mBottomRightOffset= NSMakePoint(0, 0);
    mAddPadding= NO;
    
    [self setTarget:self];
    [self setAction:@selector(performCallback:)];
  }
  return self;
}


- (void)performCallback:(id)sender
{
  mOwner->callback();
}


static bool checkbox_create(::mforms::CheckBox *self, bool square)
{
  [[[MFCheckBoxImpl alloc] initWithObject:self square:square] autorelease];
  return true;
}

static void checkbox_set_active(::mforms::CheckBox *self, bool flag)
{
  if ( self )
  {
    MFCheckBoxImpl* checkbox = self->get_data();
    
    if ( checkbox )
    {
      [checkbox setState: flag ? NSOnState : NSOffState];
    }
  }
}

static bool checkbox_get_active(::mforms::CheckBox *self)
{
  if ( self )
  {
    MFCheckBoxImpl* checkbox = self->get_data();
    
    if ( checkbox )
    {
      return [checkbox state] == NSOnState;
    }
  }
  return false;
}


void cf_checkbox_init()
{
  ::mforms::ControlFactory *f = ::mforms::ControlFactory::get_instance();
  
  f->_checkbox_impl.create= &checkbox_create;
  f->_checkbox_impl.set_active= &checkbox_set_active;
  f->_checkbox_impl.get_active= &checkbox_get_active;
}


@end

