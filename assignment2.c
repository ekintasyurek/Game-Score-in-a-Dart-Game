#include <stdio.h>

int start(int segment,char ring){
	
	int point;
	
	if(ring=='D'){
		point=segment*2;
	}
	else if(ring=='T'){
		point=segment*3;
	}
	else if(ring=='S'){
		point=segment;
	}
	else if(ring=='O'){
		point=25;
	}
	else if(ring=='I'){
		point=50;
	}
	
	return point;
}



int main(){
	
	int target, segment, newpoint, point, currentpoint;
	char ring;
	printf("Target: ");
	scanf("%d", &target);
	
	newpoint=target;
	
	printf("Throw: ");
	scanf("%d %c", &segment, &ring);
	
	while(((ring!='D')&&(ring!='S')&&(ring!='T')&&(ring!='O')&&(ring!='I'))||((segment<0)||(segment>20))){
		
		printf("Points: %d\n", target);
		printf("Throw: ");
		scanf("%d %c", &segment, &ring);
	}
	
	while(ring!='D'){
		printf("Points: %d\n", target);
		printf("Throw: ");
		scanf("%d %c", &segment, &ring);
	}
	
	if(ring=='D'){
		while(target>0){
			point = start(segment,ring);
			currentpoint = newpoint;
			newpoint = newpoint-point;
			
			
			if(newpoint<=1){
				
				while((ring!='D') || (segment!=currentpoint/2)){
					printf("Points: %d\n", currentpoint);   //IF'DEN SONRA BU KISMI 2 KERE BASMIÞ OLUYOR
					printf("Throw: ");
					scanf("%d %c", &segment, &ring);
					point = start(segment,ring);
					newpoint = currentpoint-point;
					if(newpoint>1){
						currentpoint=newpoint;
						break;
					}
				}
				
				if((ring=='D') && (segment==currentpoint/2)){
					printf("Points: 0\n");
					break;
				}
					
			}
			
			printf("Points: %d\n", newpoint);
			printf("Throw: ");
			scanf("%d %c", &segment, &ring);
		}
	}
		
	
	return 0;
}
