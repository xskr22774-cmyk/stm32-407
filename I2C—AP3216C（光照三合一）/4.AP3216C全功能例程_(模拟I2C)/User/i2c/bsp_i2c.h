#ifndef __BSP_I2C_H
#define	__BSP_I2C_H

#include "stm32f4xx.h"



/*I2C引脚*/
/* 定义I2C总线连接的GPIO端口, 用户只需要修改下面4行代码即可任意改变SCL和SDA的引脚 */
#define GPIO_PORT_I2C	          GPIOB			/* GPIO端口 */
#define I2C_GPIO_CLK_ENABLE()   __HAL_RCC_GPIOB_CLK_ENABLE()		/* GPIO端口时钟 */
#define I2C_SCL_PIN		          GPIO_PIN_8			/* 连接到SCL时钟线的GPIO */
#define I2C_SDA_PIN		          GPIO_PIN_9			/* 连接到SDA数据线的GPIO */


//软件IIC使用的宏
#define I2C_SCL_1()  HAL_GPIO_WritePin(GPIO_PORT_I2C, I2C_SCL_PIN, GPIO_PIN_SET)    /* SCL = 1 */
#define I2C_SCL_0()  HAL_GPIO_WritePin(GPIO_PORT_I2C, I2C_SCL_PIN, GPIO_PIN_RESET)  /* SCL = 0 */

#define I2C_SDA_1()  HAL_GPIO_WritePin(GPIO_PORT_I2C, I2C_SDA_PIN, GPIO_PIN_SET)  		/* SDA = 1 */
#define I2C_SDA_0()  HAL_GPIO_WritePin(GPIO_PORT_I2C, I2C_SDA_PIN, GPIO_PIN_RESET)		/* SDA = 0 */

#define I2C_SDA_READ()  HAL_GPIO_ReadPin(GPIO_PORT_I2C, I2C_SDA_PIN)	/* 读SDA口线状态 */

/*信息输出*/
#define I2C_DEBUG_ON         1
#define I2C_DEBUG_FUNC_ON    0

#define I2C_INFO(fmt,arg...)           printf("<<-I2C-INFO->> "fmt"\n",##arg)
#define I2C_ERROR(fmt,arg...)          printf("<<-I2C-ERROR->> "fmt"\n",##arg)
#define I2C_DEBUG(fmt,arg...)          do{\
                                          if(I2C_DEBUG_ON)\
                                          printf("<<-I2C-DEBUG->> [%d]"fmt"\n",__LINE__, ##arg);\
                                          }while(0)

#define I2C_DEBUG_FUNC()               do{\
                                         if(I2C_DEBUG_FUNC_ON)\
                                         printf("<<-I2C-FUNC->> Func:%s@Line:%d\n",__func__,__LINE__);\
                                       }while(0)

/*设定的AP3216C IIC设备地址*/
#define AP3216C_ADDR  0x3C
#define I2C_DIR_WR	  0		/* 写控制bit */
#define I2C_DIR_RD	  1		/* 读控制bit */

//函数接口
void i2c_Start(void);
void i2c_Stop(void);
void i2c_SendByte(uint8_t _ucByte);
uint8_t i2c_ReadByte(void);
uint8_t i2c_WaitAck(void);
void i2c_Ack(void);
void i2c_NAck(void);
uint8_t i2c_CheckDevice(uint8_t _Address);
void i2c_GPIO_Config(void);

#endif /* __BSP_I2C */
