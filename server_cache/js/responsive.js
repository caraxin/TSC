HTTP/1.1 200 OK
Content-Type: application/javascript
Last-Modified: Thu, 01 May 2014 19:09:20 GMT
Vary: Accept-Encoding
ETag: W/"53629be0-e66"
Expires: Mon, 12 Mar 2018 08:26:52 GMT
Cache-Control: no-store
Pragma: public
Transfer-Encoding: chunked
Date: Sun, 12 Mar 2017 08:26:52 GMT
Age: 0
Connection: close
X-Cache: MISS

00e66
��/ *   : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : 
 	 
 	 R E S P O N S I V E   S C R I P T S 
 	 
 : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : : * / 
 $ ( d o c u m e n t ) . r e a d y ( f u n c t i o n ( )   { 
 
 	 
 	 / / M O B I L E   M E N U S 
 	 v a r   m o b i l e N a v O p e n   =   0 ;   / / m o b i l e   n a v   c l o s e d 
 	 
 	 $ ( ' # n a v - c o n t r o l ' ) . c l i c k ( f u n c t i o n ( ) { 
 	 	 i f   ( m o b i l e N a v O p e n   = =   0 ) { 
 	 	 	 $ ( ' # h e a d e r - n a v ' ) . s l i d e D o w n ( 3 0 0 ) ; 
 	 	 	 $ ( ' # t o p - b a r ' ) . s l i d e D o w n ( 3 0 0 ) ; 
 	 	 	 $ ( t h i s ) . a d d C l a s s ( " o p e n " ) ; 
 	 	 	 m o b i l e N a v O p e n   =   1 ; 
 	 	 	 r e t u r n   f a l s e ; 
 	 	 } 
 	 	 e l s e   { 
 	 	 	 $ ( ' # h e a d e r - n a v ' ) . s l i d e U p ( 3 0 0 ) ; 
 	 	 	 $ ( ' # t o p - b a r ' ) . s l i d e U p ( 3 0 0 ) ; 
 	 	 	 $ ( t h i s ) . r e m o v e C l a s s ( " o p e n " ) ; 
 	 	 	 m o b i l e N a v O p e n   =   0 ; 
 	 	 	 r e t u r n   f a l s e ; 
 	 	 } 	 
 	 } ) ; 
 	 
 	 
 	 v a r   b o d y W i d t h   =   $ ( " b o d y " ) . i n n e r W i d t h ( ) ;   / / n o   s c r o l l b a r s 
 	 
 	 	 
 	 / / M A I N   N A V   D R O P D O W N S 
 	 v a r   i s A c t i o n B o u n d ; 
 
         i f   ( b o d y W i d t h   < =   8 0 3 )   { 
 	 	 $ ( " . d r o p d o w n - l i n k " ) . u n b i n d ( " c l i c k " , d r o p D o w n M e n u ) ; 
 	 	 i s A c t i o n B o u n d   =   0 ; 
 	 	 
 	 	 $ ( " # t o p - b a r " ) . h i d e ( ) ; 
 	 	 $ ( " # h e a d e r - n a v " ) . h i d e ( ) ; 
 	 	 $ ( " # n a v - c o n t r o l " ) . s h o w ( ) ; 
 	 	 $ ( " # s e a r c h b o x " ) . s h o w ( ) ; 	 
         } 
 	 e l s e   { 
 	 	 i s A c t i o n B o u n d   =   1 ; 
 	 } 
 
 	 f u n c t i o n   b i n d A c t i o n T o D r o p d o w n ( )   { 
 	 	 i f ( i s A c t i o n B o u n d   = =   0 )   { 
 	 	 	 $ ( " . d r o p d o w n - l i n k " ) . b i n d ( " c l i c k " , d r o p D o w n M e n u ) ; 
 	 	 	 i s A c t i o n B o u n d   =   1 ; 
 	 	 } 
 	 } 
 	 
 
 	 / / W I N D O W   R E S I Z E 
 	 $ ( w i n d o w ) . r e s i z e ( f u n c t i o n ( )   { 
 	 	 
 	 	 v a r   b o d y R e s i z e   =   $ ( " b o d y " ) . i n n e r W i d t h ( ) ; 
 	 	 	 	 	 
 	 	 / / M O B I L E   N A V   C O N T R O L 
 	 	 i f   ( b o d y R e s i z e   < =   8 0 3 )   { 
 	 	 	 $ ( " # n a v - c o n t r o l " ) . s h o w ( ) ; 
 	 	 }   e l s e   { 
 	 	 	 $ ( " # n a v - c o n t r o l " ) . h i d e ( ) ; 
 	 	 } 
 	 	 
 	 	 / / S H O W   O R   H I D E   N A V S 
 	 	 i f   (   ( b o d y R e s i z e   < =   8 0 3 )   & &   m o b i l e N a v O p e n   = =   0 )   { 
 	 	 	 $ ( ' # t o p - b a r ' ) . h i d e ( ) ; 
 	 	 	 $ ( ' # h e a d e r - n a v ' ) . h i d e ( ) ; 
 	 	 }   e l s e   { 
 	 	 	 $ ( ' # t o p - b a r ' ) . s h o w ( ) ; 
 	 	 	 $ ( ' # h e a d e r - n a v ' ) . s h o w ( ) ; 
 	 	 } 
 	 	 
 	 	 / / D R O P   D O W N   M E N U 
 	 	 i f   ( b o d y R e s i z e   < =   8 0 3 )   { 
 	 	 	 i s A c t i o n B o u n d   =   0 ; 
 	 	 	 $ ( " . d r o p d o w n - l i n k " ) . u n b i n d ( " c l i c k " , d r o p D o w n M e n u ) ; 
 	 	 	 $ ( " . d r o p d o w n - l i n k " ) . r e m o v e C l a s s ( " s e l e c t e d " ) ; 
 	 	 	 $ ( " . d r o p d o w n - w r a p p e r " ) . h i d e ( ) ; 
 	 	 	 $ ( " # d r o p d o w n - s p a c e r " ) . a n i m a t e ( { 
 	 	 	 	 h e i g h t :   " " 
 	 	 	 } ,   0 ) ; 
 	         }   e l s e   { 
 	 	 	 b i n d A c t i o n T o D r o p d o w n ( ) ; 
 	         } 	 
 	 } ) ; 
 
 	 
 } ) ; 
 
 
 
0

