/*****************************************************************************
 * description.h:
 *****************************************************************************
 * Copyright (C) 2012-2015 L-SMASH project
 *
 * Authors: Yusuke Nakamura <muken.the.vfrmaniac@gmail.com>
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *****************************************************************************/

/* This file is available under an ISC license. */

struct lsmash_codec_specific_list_tag
{
    lsmash_entry_list_t list;
};

lsmash_codec_specific_t *isom_duplicate_codec_specific_data
(
    lsmash_codec_specific_t *specific
);

lsmash_codec_specific_t *isom_get_codec_specific
(
    lsmash_codec_specific_list_t   *opaque,
    lsmash_codec_specific_data_type type
);

uint8_t *isom_get_child_box_position
(
    uint8_t          *parent_data,
    uint32_t          parent_size,
    lsmash_box_type_t child_type,
    uint32_t         *child_size
);

int isom_setup_visual_description
(
    isom_stsd_t            *stsd,
    lsmash_codec_type_t     sample_type,
    lsmash_video_summary_t *summary
);

int isom_setup_audio_description
(
    isom_stsd_t            *stsd,
    lsmash_codec_type_t     sample_type,
    lsmash_audio_summary_t *summary
);

int isom_setup_tx3g_description
(
    isom_stsd_t      *stsd,
    lsmash_summary_t *summary
);

lsmash_summary_t *isom_create_video_summary_from_description
(
    isom_sample_entry_t *sample_entry
);

lsmash_summary_t *isom_create_audio_summary_from_description
(
    isom_sample_entry_t *sample_entry
);

int isom_compare_opaque_extensions
(
    lsmash_summary_t *a,
    lsmash_summary_t *b
);

int isom_get_implicit_qt_fixed_comp_audio_sample_quants
(
    isom_audio_entry_t *audio,
    uint32_t           *samples_per_packet,
    uint32_t           *constant_bytes_per_frame,
    uint32_t           *sample_size
);
