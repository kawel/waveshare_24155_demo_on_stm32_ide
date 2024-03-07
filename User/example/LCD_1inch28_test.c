#include "image.h"
#include "LCD_Test.h"
#include "LCD_1in28.h"
#include "Touch_Driver.h"
#include "DEV_Config.h"

Touch_1IN28_XY XY;
UBYTE flag = 0,flgh = 0;
UWORD x,y,l = 0;

void LCD_1in28_test()
{
	printf("LCD_1IN28_test Demo\r\n");
	DEV_Module_Init();
  
  printf("LCD_1IN28_ Init and Clear...\r\n");
	LCD_1IN28_SetBackLight(1000);
	LCD_1IN28_Init(VERTICAL);

	XY.mode = 0;
	if(Touch_1IN28_init(XY.mode) == true)
        printf("OK!\r\n");
    else
        printf("NO!\r\n");
		
	printf("Paint_NewImage\r\n");
	Paint_NewImage(LCD_1IN28_WIDTH,LCD_1IN28_HEIGHT, 0, BLACK);
	
	printf("Set Clear and Display Funtion\r\n");
	Paint_SetClearFuntion(LCD_1IN28_Clear);
	Paint_SetDisplayFuntion(LCD_1IN28_DrawPaint);

  printf("Paint_Clear\r\n");
	Paint_Clear(WHITE);
		
	Paint_DrawString_EN(35, 90, "Gesture test", &Font20, BLACK, WHITE);
  Paint_DrawString_EN(10, 120, "Complete as prompted", &Font16, BLACK, WHITE);
  DEV_Delay_ms(500);
	
	Paint_ClearWindows(10,90,230,137,WHITE);  
  Paint_DrawString_EN(105, 100, "Up", &Font24, 0X647C, WHITE);
  while(XY.Gesture != UP)
  {    
		 if (flag == TOUCH_IRQ)
		 {
				XY.Gesture = I2C_Read_Byte(0x01);
				flag = TOUCH_DRAW;
		 }      
		DEV_Delay_ms(10);   
  }

	Paint_ClearWindows(105,100,160,155,WHITE);  
	Paint_DrawString_EN(85, 100, "Down", &Font24, 0X647C, WHITE);
	while(XY.Gesture != Down)
	{
			if (flag == TOUCH_IRQ)
			{
					XY.Gesture = I2C_Read_Byte(0x01);
					flag = TOUCH_DRAW;
			}    
			DEV_Delay_ms(10);     
	}

	Paint_ClearWindows(85, 100,160,155,WHITE);
	Paint_DrawString_EN(85, 100, "Left", &Font24, 0X647C, WHITE);
	while(XY.Gesture != LEFT)
	{
			if (flag == TOUCH_IRQ)
			{
					XY.Gesture = I2C_Read_Byte(0x01);
					flag = TOUCH_DRAW;
			}    
			DEV_Delay_ms(10);     
	}

	Paint_ClearWindows(85, 100,160,155,WHITE);
	Paint_DrawString_EN(80, 100, "Right", &Font24, 0X647C, WHITE);
	while(XY.Gesture != RIGHT)
	{
			if (flag == TOUCH_IRQ)
			{
					XY.Gesture = I2C_Read_Byte(0x01);
					flag = TOUCH_DRAW;
			}     
			DEV_Delay_ms(10);    
	}

	Paint_ClearWindows(80, 100,165,160,WHITE);
	Paint_DrawString_EN(47, 100, "Long Press", &Font20, 0X647C, WHITE);
	while(XY.Gesture != LONG_PRESS)
	{
			if (flag == TOUCH_IRQ)
			{
					XY.Gesture = I2C_Read_Byte(0x01);
					flag = TOUCH_DRAW;
			}     
			DEV_Delay_ms(10);    
	}

	Paint_ClearWindows(47, 100,200,155,WHITE);
	Paint_DrawString_EN(35, 100, "Double Click", &Font20, 0X647C, WHITE);
	while(XY.Gesture != DOUBLE_CLICK)
	{
			if (flag == TOUCH_IRQ)
			{
					XY.Gesture = I2C_Read_Byte(0x01);
					flag = TOUCH_DRAW;
			} 
			DEV_Delay_ms(10);        
	}

	XY.mode = 1;
	Touch_1IN28_init(XY.mode);
	
	Paint_ClearWindows(10,90,230,137,WHITE);  
	Paint_DrawRectangle(0, 0, 35, 208,RED,DOT_PIXEL_1X1,DRAW_FILL_FULL);
	Paint_DrawRectangle(0, 0, 208, 35,GREEN,DOT_PIXEL_1X1,DRAW_FILL_FULL);
	Paint_DrawRectangle(206, 0, 240, 240,BLUE,DOT_PIXEL_1X1,DRAW_FILL_FULL);
	Paint_DrawRectangle(0, 206, 240, 240,GRAY,DOT_PIXEL_1X1,DRAW_FILL_FULL);
	while (1)
	{
			if (flag == TOUCH_IRQ)
			{
					if(flgh == TOUCH_INIT && XY.x_point != TOUCH_INIT)
					{
									flgh = 1; 
									//Get the coordinates of the first point    ��ȡ��һ�ε������
									x = XY.x_point;
									y = XY.y_point;
					}
					if ((XY.x_point > 35 && XY.x_point < 205) && (XY.y_point > 35 && XY.y_point < 208))
					{
							flgh = TOUCH_DRAW;//Permit painting     ����
					}
					else
					{
							if ((XY.x_point > 0 && XY.x_point < 33) && (XY.y_point > 0 && XY.y_point < 208))
									XY.color = RED;

							if ((XY.x_point > 0 && XY.x_point < 208) && (XY.y_point > 0 && XY.y_point < 33))
									XY.color = GREEN;

							if ((XY.x_point > 208 && XY.x_point < 240) && (XY.y_point > 0 && XY.y_point < 240))
											XY.color = BLUE;

							if ((XY.x_point > 0 && XY.x_point < 240) && (XY.y_point > 208 && XY.y_point < 240))
											Paint_ClearWindows(35,35,205,205,WHITE);

							flgh = TOUCH_NO_DRAW; //No painting     ��ֹ��
							flag = TOUCH_DRAW; //Change interrupt bit      �ı��ж�λ
					}
					

					if (flgh == TOUCH_DRAW)
					{
							XY.x_point = (XY.x_point > 37)? XY.x_point : 37;
							XY.y_point = (XY.y_point > 37)? XY.y_point : 37;

							XY.x_point = (XY.x_point < 205)? XY.x_point : 205;
							XY.y_point = (XY.y_point < 203)? XY.y_point : 203;    
							
							if (l<48000) //Continuous drawing    ������
							{
									flag = TOUCH_DRAW;
									Paint_DrawLine(x,y,XY.x_point, XY.y_point, XY.color, DOT_PIXEL_2X2, LINE_STYLE_SOLID);
									l=0;
							}
							else//Draw Point    ����
							{
									flag = TOUCH_DRAW; 
									Paint_DrawPoint(XY.x_point, XY.y_point, XY.color, DOT_PIXEL_2X2, DOT_FILL_AROUND);
									l = 0; 
							}
							x = XY.x_point;
							y = XY.y_point;
					}
			}
			l++;
			if (l>50000) //Decide whether to draw dots or lines   �жϻ��㻹�ǻ���
			{
					l=49000;
			}
    }
  
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin & TP_INT_Pin)
	{
		if(XY.mode == 1)
		{
			flag = TOUCH_IRQ;
			XY = Touch_1IN28_Get_Point();
		}
		else
		{
			flag = TOUCH_IRQ;
		}
	}
}


