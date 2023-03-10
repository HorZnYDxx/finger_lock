
void record_error()
{

      if( n<n_max )  // 確定還沒有伸到最內部 還需要累進計算
          { 
            
            if (X_now > X_target) //還沒到目標 甚麼都不用做
                {  
                    //還沒到目標 甚麼都不用做
                }                
            else if(X_now == X_target)  //剛好到目標 累計誤差
                {
                  Y_error=my_abs(   Y_now  -  Y_key[n]    );
                  Y_error_sum  +=  Y_error;
                  
                  Serial.print("n=");
                  Serial.print(n);
                  Serial.print("  error_delta=  ");
                  Serial.println( Y_error );
                  

                  next();
                }
            else  // 超過目標  內插 但因為多數情形都只會超過1 也就是等距內插 因此簡化算式
                { 
                  
                  Y_error=my_abs(   (Y_last+Y_now)/2  -  Y_key[n]    );
                  Y_error_sum  +=  Y_error;
                  
                  Serial.print("n=");
                  Serial.print(n);
                  Serial.print("  error_delta_overshoot=  ");
                  Serial.println( Y_error);     
                  next();
                }
                
          }    

            X_last=X_now;   //更新準備下一個數據
            Y_last=Y_now;
                
  
}








void check_start_end()
{
      if(X_now > X_start+2 && X_target<X_start)  // 手指完全抽出 +2避免數值跳動誤判 且尚未處於準備重測的狀態(第二個條件) 避免不斷刷出資訊
    {


                  Serial.print("  error_sum=  ");
 Serial.println(Y_error);  //先輸出此輪累進後的累進錯誤值以監視
      
      X_target=X_start; //目標歸位準備重測
      Y_error_sum = 0;  //歸零準備重測
      n=0;  //歸零準備重測
            
Serial.print("  error_sum=  ");
      Serial.println(Y_error_sum);   //接下來才輸出歸零後的累進錯誤值以監視

      clear_flag=true;
      
    }
    
    if(n == n_max-1) // 手指完全伸入 檢查Y誤差值是否允許開鎖 因為迴圈從0開始算所以最後只有n_max-1個delta
    {    
      
      if(Y_error_sum < Y_allowed_error)
      {
       unlock();  
      }
      else
      {
       mismatch(); //不符合
      }
    }

}



int my_abs(int x)
{
  if(x<0)
  {
    return -1*x;
  }
  else
  {
    return x;
  }  
}
