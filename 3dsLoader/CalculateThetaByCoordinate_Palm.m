function res=CalculateThetaByCoordinate_Palm(x,y,z,a1,a2,a3,a4,L,d,isThumb)
%x,y,z
%a1,a2,a3,a4�ֱ�Ϊ����ָ�ڵĳ���
%isThumb=0��ʾ��ǰҪ����Ĳ��Ǵ�Ĵָ,�����ʾ��Ĵָ
%���ؽ��Ϊ����ָ�ؽڵ�ת���Ƕ�,theta1,theta2,theta3,theta4
% a1=20.871;
% a2=50.059;
% a3=44.621;
% a4=25.014;
% d1=-46.186;
% L1=24.331;
%�Ƚ�ָ�������Ƶ�����ת����ָ����ϵ�ؽ�����ϵ�е�����
if isThumb==0
    %�Ǵ�Ĵָ
    px=y-L;
    py=-x-d;
    pz=z;
else
    %��Ĵָ
    px=x+d;
    py=y-L;
    pz=z;
end

[res]=CalculateThetaByCoordinate(px,py,pz,a1,a2,a3,a4);
end