#ifndef __LINUX_LP5523_H
#define __LINUX_LP5523_H

struct lp5523_led_config {
	u8		chan_nr;
	u8		led_current; /* mA x10, 0 if led is not connected */
};

#define LP5523_CLOCK_AUTO	0
#define LP5523_CLOCK_INT	1
#define LP5523_CLOCK_EXT	2

struct lp5523_platform_data {
	struct lp5523_led_config *led_config;
	u8	num_channels;
	u8	clock_mode;
	int	(*setup_resources)(void);
	void	(*release_resources)(void);
	void	(*enable)(bool state);
};

#endif /* __LINUX_LP5523_H */
