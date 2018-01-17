/* usbemu - USB Emulation Library
 * Copyright (C) 2018 You-Sheng Yang
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#if !defined (__USBEMU_USBEMU_H_INSIDE__) && !defined (LIBUSBEMU_COMPILATION)
#error "Only <usbemu/usbemu.h> can be included directly."
#endif

#include <glib-object.h>

#include <usbemu/usbemu-configuration.h>

G_BEGIN_DECLS

/**
 * USBEMU_TYPE_INTERFACE:
 *
 * Convenient macro for usbemu_interface_get_type().
 */
#define USBEMU_TYPE_INTERFACE  (usbemu_interface_get_type ())

G_DECLARE_DERIVABLE_TYPE (UsbemuInterface, usbemu_interface, USBEMU, INTERFACE,
                          GObject)

/**
 * USBEMU_INTERFACE_PROP_INTERFACE_NUMBER:
 *
 * "interface-number" property name.
 */
#define USBEMU_INTERFACE_PROP_INTERFACE_NUMBER "interface-number"
/**
 * USBEMU_INTERFACE_PROP_ALTERNATE_SETTING:
 *
 * "alternate-setting" property name.
 */
#define USBEMU_INTERFACE_PROP_ALTERNATE_SETTING "alternate-setting"
/**
 * USBEMU_INTERFACE_PROP_NAME:
 *
 * "name" property name.
 */
#define USBEMU_INTERFACE_PROP_NAME "name"
/**
 * USBEMU_INTERFACE_PROP_CLASS:
 *
 * "class" property name.
 */
#define USBEMU_INTERFACE_PROP_CLASS "class"
/**
 * USBEMU_INTERFACE_PROP_SUB_CLASS:
 *
 * "sub-class" property name.
 */
#define USBEMU_INTERFACE_PROP_SUB_CLASS "sub-class"
/**
 * USBEMU_INTERFACE_PROP_PROTOCOL:
 *
 * "protocol" property name.
 */
#define USBEMU_INTERFACE_PROP_PROTOCOL "protocol"

struct _UsbemuInterfaceClass {
  GObjectClass parent_class;

  /*< private >*/

  /* Reserved slots for furture extension. */
  gpointer padding[12];
};

UsbemuInterface* usbemu_interface_new      ();
UsbemuInterface* usbemu_interface_new_full (const gchar   *name,
                                            UsbemuClasses  klass,
                                            guint          sub_class,
                                            guint          protocol);

guint         usbemu_interface_get_interface_number  (UsbemuInterface *interface);
guint         usbemu_interface_get_alternate_setting (UsbemuInterface *interface);
const gchar*  usbemu_interface_get_name              (UsbemuInterface *interface);
void          usbemu_interface_set_name              (UsbemuInterface *interface,
                                                      const gchar     *name);
UsbemuClasses usbemu_interface_get_class             (UsbemuInterface *interface);
void          usbemu_interface_set_class             (UsbemuInterface *interface,
                                                      UsbemuClasses    klass);
guint         usbemu_interface_get_sub_class         (UsbemuInterface *interface);
void          usbemu_interface_set_sub_class         (UsbemuInterface *interface,
                                                      guint            sub_class);
guint         usbemu_interface_get_protocol          (UsbemuInterface *interface);
void          usbemu_interface_set_protocol          (UsbemuInterface *interface,
                                                      guint            protocol);

UsbemuConfiguration* usbemu_interface_get_configuration (UsbemuInterface *interface);

G_END_DECLS
