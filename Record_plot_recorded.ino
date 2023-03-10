
void Record_key()
{
n=0;

color(LOW,LOW,HIGH);

       while (n < n_max)
       {

              X_now = analogRead(2);
              Y_now = analogRead(3);
        
             if (X_now > X_target) //還沒到目標 甚麼都不用做
                {  
                    //還沒到目標 甚麼都不用做
                }
            else if(X_now == X_target)  //剛好到目標 記錄數據
                {
             
                  Y_key[n]=Y_now;
                  next();
                }
            else // 超過目標了  //內插 但因為多數情形都只會超過1 也就是等距內插 因此簡化算式
                { 
                 
                  Y_key[n]=(Y_last+Y_now)/2;
                  next();
                }

            X_last=X_now;   //更新準備下一個數據
            Y_last=Y_now;
                
          }

EEPROM_writeAnything(0,Y_key);  //用儲存X_key,因為從n就可以知道了! 節省sram和eeprom

  digitalWrite(R ,LOW);
  digitalWrite(G ,LOW);
  digitalWrite(B ,LOW);

plotKey();
          
}



void next()
{


   //  E.SendData("E",  X_target, Y_error  );  // E= Error 
     E.SendData("ES",  X_target, Y_error_sum  );  // ES =Error sum
     Fi.SendData("F", X_target, Y_now);  //F = finger  short to speed up

  
     n++;
     X_target+=X_delta; 

      if (clear_flag)
      {
          Fi.Clear("F");
          E.Clear();

          
          clear_flag=false;
      }

      

}





void plotKey()
{

Fi.Clear();
  
    for(int i=0; i<n_max ; i++  )
    {    
    Fi.SendData("K", X_start  + i * X_delta , Y_key[i]);  //K for key
    delay(20);
    }

 
}

