uniform sampler2D texture;

uniform int way;
uniform float elapsed; // In seconds
uniform float duration;

bool isFadeDone()
{
   return elapsed == duration;
}

void main()
{
   vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);
   vec4 color = gl_Color * pixel;
   float alphaFactor = way == 0 ? elapsed / duration : 1 - (elapsed / duration);

   if (isFadeDone() && way == 0)
      gl_FragColor = color;
   else if (isFadeDone() && way == 1)
      gl_FragColor = vec4(color.xyz, 0);
   else
      gl_FragColor = vec4(color.xyz, color.w * alphaFactor);
}

