# CerberusSDL2_Mixer

SDL2 Mixer binding for Cerberus-X framework

# Test

Cerberus-X test code:

``` monkey
Import sdl2mixer
Import mojo

Function Main()
	New TestMikmod()
End Function

Class TestMikmod Extends App
	
	Method OnCreate()
		SDL2Mixer_Open()
		SDL2Mixer_FadeIn("data/1.xm", False, 3000)
	End Method
	
	Method OnUpdate()
	
		If KeyHit(KEY_SPACE)

		Endif
		If KeyHit(KEY_ESCAPE)
			SDL2Mixer_FadeOut(5000)
		Endif
	
	End Method

	Method OnRender()
		Cls 255,255,255
	End Method
	
	Method OnResume()	
		SDL2Mixer_Resume()
	End Method

	Method OnSuspend()	
		SDL2Mixer_Pause()
	End Method

	Method OnClose()
		SDL2Mixer_Close
		EndApp()
	End Method	
	
End Class
```
