/* SPDX-License-Identifier: MIT */
/*
 * Copyright © 2023 Intel Corporation
 */

#ifndef __INTEL_FBDEV_FB_H__
#define __INTEL_FBDEV_FB_H__

#include <linux/version.h>

struct drm_fb_helper;
struct drm_fb_helper_surface_size;
#if LINUX_VERSION_CODE < KERNEL_VERSION(6, 13, 0)
struct drm_i915_gem_object;
#else
struct drm_gem_object;
#endif
struct drm_i915_private;
struct fb_info;
struct i915_vma;

struct intel_framebuffer *intel_fbdev_fb_alloc(struct drm_fb_helper *helper,
					       struct drm_fb_helper_surface_size *sizes);
#if LINUX_VERSION_CODE < KERNEL_VERSION(6, 13, 0)
int intel_fbdev_fb_fill_info(struct drm_i915_private *i915, struct fb_info *info,
			     struct drm_i915_gem_object *obj, struct i915_vma *vma);
#else
int intel_fbdev_fb_fill_info(struct drm_i915_private *i915, struct fb_info *info,
			     struct drm_gem_object *obj, struct i915_vma *vma);
#endif

#endif
