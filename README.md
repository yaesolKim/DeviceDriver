## 미션 1 : Device Driver 구현
✔Device Driver, Read 기능 개발 명세서  
▪ Read를 5회 수행한다.  
▪ 5회의 Read의 결과가 모두 같은 값일 때, 읽은 값을 return 한다.  
• 모두 같은 값이 아니라면, Custom Exception(ReadFailException)을 발생시킨다.  
✔Device Driver, Write 기능 개발 명세서  
▪ 해당 객체에 이미 값이 적혀 있는지 확인한다.  
(읽었을 때 0xFF라면, 값이 지워진 상태이다.)  
▪ 값이 적혀 있지 않을 때, 해당 주소에 값을 Write한다.  
• 이미 값이 적혀 있다면 Custom Exception(WriteFailException)을 발생시킨다  


## 미션 2 : application 구현   
✔readAndPrint(startAddr, endAddr) 함수  
▪ startAddr ~ endAddr 까지 Read 수행 후 결과 출력  
✔writeAll(value) 함수  
▪ 0x00 ~ 0x04 까지 모두 value 값으로 Write한다  
