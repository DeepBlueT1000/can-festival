/*
 * File      : application.c
 * This file is part of RT-Thread RTOS
 * COPYRIGHT (C) 2006, RT-Thread Development Team
 *
 * The license and distribution terms for this file may be
 * found in the file LICENSE in this distribution or at
 * http://www.rt-thread.org/license/LICENSE
 *
 * Change Logs:
 * Date           Author       Notes
 * 2009-01-05     Bernard      the first version
 * 2013-07-12     aozima       update for auto initial.
 */

/**
 * @addtogroup STM32
 */
/*@{*/

#include <board.h>
#include <rtthread.h>

#ifdef  RT_USING_COMPONENTS_INIT
#include <components.h>
#endif  /* RT_USING_COMPONENTS_INIT */

#ifdef RT_USING_DFS
/* dfs filesystem:ELM filesystem init */
#include <dfs_elm.h>
/* dfs Filesystem APIs */
#include <dfs_fs.h>
#endif

#ifdef RT_USING_RTGUI
#include <rtgui/rtgui.h>
#include <rtgui/rtgui_server.h>
#include <rtgui/rtgui_system.h>
#include <rtgui/driver.h>
#include <rtgui/calibration.h>
#endif

#include "led.h"

ALIGN(RT_ALIGN_SIZE)
static rt_uint8_t led_stack[ 512 ];
static struct rt_thread led_thread;

void can_recv_thread(void* parameter);
void can_send_thread(void *parameter);

static void led_thread_entry(void* parameter)
{
    unsigned int count=0;

    rt_hw_led_init();

    while (1)
    {
        /* led1 on */
#ifndef RT_USING_FINSH
        //rt_kprintf("led on, count : %d\r\n",count);
#endif
        count++;
        rt_hw_led_on(0);
        rt_thread_delay( RT_TICK_PER_SECOND/2 ); /* sleep 0.5 second and switch to other thread */

        /* led1 off */
#ifndef RT_USING_FINSH
        //rt_kprintf("led off\r\n");
#endif
        rt_hw_led_off(0);
        rt_thread_delay( RT_TICK_PER_SECOND/2 );
    }
}

#ifdef RT_USING_RTGUI
rt_bool_t cali_setup(void)
{
    rt_kprintf("cali setup entered\n");
    return RT_FALSE;
}

void cali_store(struct calibration_data *data)
{
    rt_kprintf("cali finished (%d, %d), (%d, %d)\n",
               data->min_x,
               data->max_x,
               data->min_y,
               data->max_y);
}
#endif /* RT_USING_RTGUI */

void rt_init_thread_entry(void* parameter)
{
#ifdef RT_USING_COMPONENTS_INIT
    /* initialization RT-Thread Components */
    rt_components_init();
#endif

#ifdef  RT_USING_FINSH
    finsh_set_device(RT_CONSOLE_DEVICE_NAME);
#endif  /* RT_USING_FINSH */
}

int rt_application_init(void)
{
    rt_thread_t init_thread;

    rt_err_t result;
  	rt_thread_t tt = RT_NULL;

    /* init led thread */
    result = rt_thread_init(&led_thread,
                            "led",
                            led_thread_entry,
                            RT_NULL,
                            (rt_uint8_t*)&led_stack[0],
                            sizeof(led_stack),
                            20,
                            5);
    if (result == RT_EOK)
    {
        rt_thread_startup(&led_thread);
    }

    /* init can_recv_thread*/
    tt = rt_thread_create( "can_recv_thread",
                            can_recv_thread,
                            0,
                            512,
                            20,
                            5);
    if (tt != RT_NULL)
    {
        rt_thread_startup(tt);
    }
	tt= RT_NULL;

    /* init can_send_thread*/
    tt = rt_thread_create( "can_send_thread",
                            can_send_thread,
                            0,
                            512,
                            21,
                            5);
    if (tt != RT_NULL)
    {
        rt_thread_startup(tt);
    }

#if (RT_THREAD_PRIORITY_MAX == 32)
    init_thread = rt_thread_create("init",
                                   rt_init_thread_entry, RT_NULL,
                                   2048, 8, 20);
#else
    init_thread = rt_thread_create("init",
                                   rt_init_thread_entry, RT_NULL,
                                   2048, 80, 20);
#endif

    if (init_thread != RT_NULL)
        rt_thread_startup(init_thread);

    return 0;
}

/*@}*/
