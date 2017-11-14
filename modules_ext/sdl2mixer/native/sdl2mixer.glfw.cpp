/*
 * https://github.com/IvelleGames/CerberusSDL2_Mixer
 */

#include <SDL2/SDL_mixer.h>

void SDL2_Mixer_Open() {

	int mixer_flags = MIX_INIT_MOD | MIX_INIT_MODPLUG;

	int initted = Mix_Init(mixer_flags);
	if ((initted & mixer_flags) != mixer_flags) {
		printf("Mix_Init: Failed to init required MIX_INIT_MOD | MIX_INIT_MODPLUG support!\n");
		// do nothing
	}

	SDL_version compile_version;
	const SDL_version *link_version = Mix_Linked_Version();
	SDL_MIXER_VERSION(&compile_version);
	printf("compiled with SDL_mixer version: %d.%d.%d\n", compile_version.major, compile_version.minor, compile_version.patch);
	printf("running with SDL_mixer version: %d.%d.%d\n", link_version->major, link_version->minor, link_version->patch);

	// open 44.1KHz, signed 16bit, system byte order, stereo audio, using 1024 byte chunks
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1) {
		// do nothing
	}

}

void SDL2_Mixer_Stop() {
	Mix_HaltMusic();
}

void SDL2_Mixer_Close() {
	SDL2_Mixer_Stop();
	Mix_CloseAudio();
	Mix_Quit();
}


Mix_Music* SDL2_Mixer_Load(String path) {

	path = BBGlfwGame::GlfwGame()->PathToFilePath(path);

	char file[path.Length()];
	size_t ret = std::wcstombs(file, path.Data(), path.Length());

	if (ret == path.Length()) {
		file[path.Length()] = '\0';
	}

	Mix_Music* music = Mix_LoadMUS(file);

	return music;

}

void SDL2_Mixer_Play(String path, bool loop) {

	SDL2_Mixer_Stop();

	Mix_Music* music = SDL2_Mixer_Load(path);

	if (music) {
		Mix_PlayMusic(music, loop ? -1 : 0);
	}

}

void SDL2_Mixer_FadeIn(String path, bool loop, int ms) {

	SDL2_Mixer_Stop();

	Mix_Music* music = SDL2_Mixer_Load(path);

	if (music) {
		Mix_FadeInMusic(music, loop ? -1 : 0, ms);
	}

}

void SDL2_Mixer_FadeOut(int ms) {
	Mix_FadeOutMusic(ms);
}

void SDL2_Mixer_Resume() {
	Mix_ResumeMusic();
}

void SDL2_Mixer_Pause() {
	Mix_PauseMusic();
}

void SDL2_Mixer_SetVolume(int volume) {
	if (volume > MIX_MAX_VOLUME) {
		volume = MIX_MAX_VOLUME;
	}
	Mix_VolumeMusic(volume);
}

int SDL2_Mixer_GetVolume() {
	return Mix_VolumeMusic(-1);
}

