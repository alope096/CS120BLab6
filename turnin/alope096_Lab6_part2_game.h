enum States{Start,LED1,LED2,LED4,LED1Hold,LED2Hold,LED4Hold,LED1Rel,LED2Rel,LED4Rel,LED1Cnt,LED2Cnt,LED4Cnt,Continue}state;

void Tick(){

    unsigned char led = 0x00;
    unsigned char button;

    button = ~PINA & 0x01;
    switch(state){
        case Start:
            state = LED1;
        break;
        case LED1:
            /*if(button){
                state = LED1Hold;
            }
            else{
                state = LED2;
            }*/
            state = button? LED1Hold:LED2;
        break;
        case LED2:
            if(button){
                state = LED2Hold;
            }
            else{
                state = LED4;
            }
        break;
        case LED4:
            if(button){
                state = LED4Hold;
            }
            else{
                state = Start;
            }
        break;

        case LED1Hold:
            if(!button){
                state = LED1Rel;
            }
            else{
                state = LED1Hold;
            }
        break;
        case LED2Hold:
            if(!button){
                state = LED2Rel;
            }
            else{
                state = LED2Hold;
            }
        break;
        case LED4Hold:
            if(!button){
                state = LED4Rel;
            }
            else{
                state = LED4Hold;
            }
        break;

        case LED1Rel:
            if(button){
                state = LED1Cnt;
            }
            else{
                state = LED1Rel;
            }
        break;
        case LED2Rel:
            if(button){
                state = LED2Cnt;
            }
            else{
                state = LED2Rel;
            }
        break;
        case LED4Rel:
            if(button){
                state = LED4Cnt;
            }
            else{
                state = LED4Rel;
            }
        break;

        case LED1Cnt:
            if(!button){
                state = Continue;
            }
            else{
                state = LED1Cnt;
            }
        break;
        case LED2Cnt:
            if(!button){
                state = Continue;
            }
            else{
                state = LED2Cnt;
            }
        break;
        case LED4Cnt:
            if(!button){
                state = Continue;
            }
            else{
                state = LED4Cnt;
            }
        break;

        case Continue:
        break;

        default:
        break;

    }
    switch(state){
        case Start:
            led = 0x01;
        break;
        case LED1:
            led = 0x01;
        break;
        case LED2:
            led = 0x02;
        break;
        case LED4:
            led = 0x04;
        break;
        case LED1Hold:
            led = 0x01;
        break;
        case LED2Hold:
            led = 0x02;
        break;
        case LED4Hold:
            led = 0x04;
        break;
        case LED1Rel:
            led = 0x01;
        break;
        case LED2Rel:
            led = 0x02;
        break;
        case LED4Rel:
            led = 0x04;
        break;
        case LED1Cnt:
          //  led = 0x01;
        break;
        case LED2Cnt:
          //  led = 0x02;
        break;
        case LED4Cnt:
            //led = 0x04;
        break;
        case Continue:
            led = 0x01;
        break;

    }
    PORTB =led;
}
/*        case Start:
        break;
        case LED1:
        break;
        case LED2:
        break;
        case LED4:
        break;
        case LED1Hold:
        break;
        case LED2Hold:
        break;
        case LED4Hold:
        break;
        case LED1Rel:
        break;
        case LED2Rel:
        break;
        case LED4Rel:
        break;
        case LED1Cnt:
        break;
        case LED2Cnt:
        break;
        case LED4Cnt:
        break;
        case Continue:
        break;
        default:
        break;
            if(){
            }
            else{
            }
*/

