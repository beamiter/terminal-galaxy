struct ConfigItem config[] = {
    { .s = "Options",  .n = "login_shell",        .t = BOOLEAN,     .v.b = TRUE                                },
    { .s = "Options",  .n = "bold_is_bright",     .t = BOOLEAN,     .v.b = FALSE                               },
    { .s = "Options",  .n = "fonts",              .t = STRINGLIST,  .v.sl = (char *[]){"Monospace 9"},  .l = 1 },
    { .s = "Options",  .n = "scrollback_lines",   .t = INT64,       .v.i = 50000                               },
    { .s = "Options",  .n = "link_regex",         .t = STRING,      .v.s = "[a-z]+://[[:graph:]]+"             },
    { .s = "Options",  .n = "link_handler",       .t = STRING,      .v.s = "xiate-link-handler"                },
    { .s = "Options",  .n = "history_handler",    .t = STRING,      .v.s = "xiate-history-handler"             },
    { .s = "Options",  .n = "cursor_blink_mode",  .t = STRING,      .v.s = "VTE_CURSOR_BLINK_OFF"              },
    { .s = "Options",  .n = "cursor_shape",       .t = STRING,      .v.s = "VTE_CURSOR_SHAPE_BLOCK"            },

    { .s = "Colors",  .n = "foreground",         .t = STRING,  .v.s = "#AAAAAA" },
    { .s = "Colors",  .n = "background",         .t = STRING,  .v.s = "#000000" },
    { .s = "Colors",  .n = "cursor",             .t = STRING,  .v.s = "#00FF00" },
    { .s = "Colors",  .n = "cursor_foreground",  .t = STRING,  .v.s = "#000000" },
    { .s = "Colors",  .n = "bold",               .t = STRING,  .v.s = NULL      },

    { .s = "Colors",  .n = "dark_black",    .t = STRING,  .v.s = "#000000" },
    { .s = "Colors",  .n = "dark_red",      .t = STRING,  .v.s = "#AA0000" },
    { .s = "Colors",  .n = "dark_green",    .t = STRING,  .v.s = "#00AA00" },
    { .s = "Colors",  .n = "dark_yellow",   .t = STRING,  .v.s = "#AA5500" },
    { .s = "Colors",  .n = "dark_blue",     .t = STRING,  .v.s = "#0000AA" },
    { .s = "Colors",  .n = "dark_magenta",  .t = STRING,  .v.s = "#AA00AA" },
    { .s = "Colors",  .n = "dark_cyan",     .t = STRING,  .v.s = "#00AAAA" },
    { .s = "Colors",  .n = "dark_white",    .t = STRING,  .v.s = "#AAAAAA" },

    { .s = "Colors",  .n = "bright_black",    .t = STRING,  .v.s = "#555555" },
    { .s = "Colors",  .n = "bright_red",      .t = STRING,  .v.s = "#FF5555" },
    { .s = "Colors",  .n = "bright_green",    .t = STRING,  .v.s = "#55FF55" },
    { .s = "Colors",  .n = "bright_yellow",   .t = STRING,  .v.s = "#FFFF55" },
    { .s = "Colors",  .n = "bright_blue",     .t = STRING,  .v.s = "#5555FF" },
    { .s = "Colors",  .n = "bright_magenta",  .t = STRING,  .v.s = "#FF55FF" },
    { .s = "Colors",  .n = "bright_cyan",     .t = STRING,  .v.s = "#55FFFF" },
    { .s = "Colors",  .n = "bright_white",    .t = STRING,  .v.s = "#FFFFFF" },

    { .s = "Controls",  .n = "button_link",               .t = UINT64,  .v.ui = 3  },
    { .s = "Controls",  .n = "key_copy_to_clipboard",     .t = STRING,  .v.s = "C" },
    { .s = "Controls",  .n = "key_paste_from_clipboard",  .t = STRING,  .v.s = "V" },
    { .s = "Controls",  .n = "key_handle_history",        .t = STRING,  .v.s = "H" },
    { .s = "Controls",  .n = "key_next_font",             .t = STRING,  .v.s = "N" },
    { .s = "Controls",  .n = "key_previous_font",         .t = STRING,  .v.s = "P" },
    { .s = "Controls",  .n = "key_zoom_in",               .t = STRING,  .v.s = "I" },
    { .s = "Controls",  .n = "key_zoom_out",              .t = STRING,  .v.s = "O" },
    { .s = "Controls",  .n = "key_zoom_reset",            .t = STRING,  .v.s = "R" },
};