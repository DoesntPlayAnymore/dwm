/* See LICENSE file for copyright and license details. */
#ifndef CUSTPROCC
#define CUSTPROCC
#include "custproc.c"
#endif
/*
#ifndef DWMC
#define DWMC
#endif
*/


/* appearance */
static const unsigned int borderpx  = 3;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int gappx     = 21; 		/* window tile gap.*/
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "monospace:size=14" };
static const char dmenufont[]       = "monospace:size=14";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char col_green[]        = "#00aa33";
static const char col_orange[]        = "#FFaa33";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_orange  },
};

/* tagging */
static const char *tags[] = { "Q", "W", "E", "A", "S", "D", "Z", "X", "C"} ;

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class                       instance    title       tags mask     isfloating   monitor */
	{ "Gimp",    		       NULL,       NULL,       0,            1,           -1 },
	{ "Firefox", 		       NULL,       NULL,       1 << 8,       0,           -1 },
	{ "Firefox Developer Edition", NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define ALTKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *pwdcmd[]   = { "cat", "~/.lastpwd", NULL };
static const char *termcmd[]  = { "terminator", NULL };
static const char *killslcmd[]= { "pkill", "slstatus", NULL };
static const char *xblincrcmd[]   = { "xbacklight", "-inc", "+10", NULL };
static const char *xbldecrcmd[]   = { "xbacklight", "-inc", "-10", NULL };
static const char *xvoldecrcmd[]   = { "amixer", "sset", "Master", "66", NULL };
static const char *xvolincrcmd[]   = { "amixer", "sset", "Master", "100", NULL };
static const char *xvolmutecmd[]   = { "amixer", "sset", "Master", "0", NULL };
static const char *surfcmd[]      = { "surf","duckduckgo.com", NULL };
static const char *randwpcmd[]      = { "/home/pro/.scripts/randwp", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_f,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_g,      spawn,          {.v = termcmd  } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ ALTKEY,                       XK_Tab,    focusstack,     {.i = +1 } },
	{ ALTKEY|ShiftMask,             XK_Tab,    focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_k,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_j,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_l,      zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_k,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_n,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },

	/* User defined. */
 	{ MODKEY,                       XK_v,      spawn,          {.v = surfcmd     }   },
 	{ MODKEY,                       XK_p,      spawn,          {.v = randwpcmd   }   },
	{ 0,                            0x1008ff03,spawn,          {.v = xbldecrcmd  }   },
	{ 0,                            0x1008ff02,spawn,          {.v = xblincrcmd  }   },
	{ 0,                            0x1008ff11,spawn,          {.v = xvoldecrcmd }   },
	{ 0,                            0x1008ff13,spawn,          {.v = xvolincrcmd }   },
	{ 0,                            0x1008ff12,spawn,          {.v = xvolmutecmd }   },
	{ 0,                            0xff61,    spawn_scrot,    {.v = "~/Pictures/scr/"} },

	/* Tag keys. */
	TAGKEYS(                        XK_q,                      0)
	TAGKEYS(                        XK_w,                      1)
	TAGKEYS(                        XK_e,                      2)
	TAGKEYS(                        XK_a,                      3)
	TAGKEYS(                        XK_s,                      4)
	TAGKEYS(                        XK_d,                      5)
	TAGKEYS(                        XK_z,                      6)
	TAGKEYS(                        XK_x,                      7)
	TAGKEYS(                        XK_c,                      8)
  	{ MODKEY|ShiftMask,             XK_r,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

