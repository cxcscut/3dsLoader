%%%%%%%%%%%%%%%%���˶�ѧ���������˶�ѧ���㣬��֤��ʽ����ȷ��%%%%
clc;
a1=20.871;
a2=50.059;
a3=44.621;
a4=25.014;
t1= -72.52;
t2=74.93;
t3=82.74;
t4=(2*t3)/3;
fprintf('�ĸ�ָ�ؽ�ȡֵ�Ƕ�����:\n');
fprintf('theta1=%.2f,theta2=%.2f,theta3=%.2f,theta4=%.2f\n',t1,t2,t3,t4);

theta1=(t1*pi)/180;
theta2=(t2*pi)/180;
theta3=(t3*pi)/180;
theta4=(2/3)*theta3;
px=cos(theta1)*(a1+a2*cos(theta2)+a3*cos(theta2+theta3)+a4*cos(theta2+theta3+theta4));
py=sin(theta1)*(a1+a2*cos(theta2)+a3*cos(theta2+theta3)+a4*cos(theta2+theta3+theta4));
pz=(a2*sin(theta2)+a3*sin(theta2+theta3)+a4*sin(theta2+theta3+theta4));
fprintf('����õ�������Ϊ:x=%.2f,y=%.2f,z=%.2f\n', px,py,pz)    

[res]=CalculateThetaByCoordinate(px,py,pz,a1,a2,a3,a4);
fprintf('ʵ����Ϊ:theta1=%.2f,theta2=%.2f,theta3=%.2f,theta4=%.2f\n', res)