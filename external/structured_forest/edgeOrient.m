function O = edgeOrient( E, r )
% compute very approximate orientation map from edge map
% E2=convTri(E,r); f=[-1 2 -1];
% Dx=conv2(E2,f,'same'); Dy=conv2(E2,f','same');
% F=conv2(E2,[1 0 -1; 0 0 0; -1 0 1],'same')>0;
% Dy(F)=-Dy(F); O=mod(atan2(Dy,Dx),pi);

[Ox,Oy]=gradient2(convTri(single(E),r));
[Oxx,~]=gradient2(Ox); [Oxy,Oyy]=gradient2(Oy);
O=mod(atan(Oyy.*sign(-Oxy)./(Oxx+1e-5)),pi);
  
end